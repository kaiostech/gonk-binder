/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include "ConnectivityInheritServer.h"
#include <binder/IInterface.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>

#define KAIOS_CON_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_ConnectivityServer", ##args)

using android::ProcessState;
using android::sp;
using android::binder::Status;
using b2g::connectivity::CaptivePortalLandingParcel;
using b2g::connectivity::ICaptivePortalLandingListener;
using b2g::connectivity::IConnectivityEventListener;
using b2g::connectivity::ITetheringStatusListener;
using b2g::connectivity::NetworkInfoParcel;
using b2g::connectivity::TetheringStatusParcel;

ConnectivityInheritServer::ConnectivityInheritServer() {
  InitNetworkInfo(mActiveNetworkInfo);
  android::defaultServiceManager()->addService(
      android::String16(getServiceName()), this);
  sp<ProcessState> process(ProcessState::self());
  process->startThreadPool();
}

Status ConnectivityInheritServer::isAlive(bool* aLive) {
  *aLive = true;
  return Status::ok();
}

// Network function
Status ConnectivityInheritServer::addEventListener(
    const sp<IConnectivityEventListener>& listener) {
  std::lock_guard lock(mNetworkEventMutex);

  class DeathRecipient : public android::IBinder::DeathRecipient {
   public:
    DeathRecipient(ConnectivityInheritServer* connectivityInheritServer,
                   sp<IConnectivityEventListener> listener)
        : mConnectivityInheritServer(connectivityInheritServer),
          mListener(std::move(listener)) {}
    ~DeathRecipient() override = default;
    void binderDied(const android::wp<android::IBinder>& /* who */) override {
      KAIOS_CON_DEBUG("Client is dead, remove listener");
      mConnectivityInheritServer->removeEventListener(mListener);
    }

   private:
    ConnectivityInheritServer* mConnectivityInheritServer;
    sp<IConnectivityEventListener> mListener;
  };
  sp<android::IBinder::DeathRecipient> deathRecipient =
      new DeathRecipient(this, listener);

  android::IInterface::asBinder(listener)->linkToDeath(deathRecipient);

  mConnectivityInheritListenerMap.insert({listener, deathRecipient});
  return Status::ok();
}

Status ConnectivityInheritServer::removeEventListener(
    const sp<IConnectivityEventListener>& listener) {
  std::lock_guard lock(mNetworkEventMutex);
  mConnectivityInheritListenerMap.erase(listener);
  return Status::ok();
}

Status ConnectivityInheritServer::getActiveNetworkInfo(
    NetworkInfoParcel* aNetworkInfoParcel) {
  *aNetworkInfoParcel = mActiveNetworkInfo;
  return Status::ok();
}

Status ConnectivityInheritServer::getNetworkInfos(
    std::vector<NetworkInfoParcel>* aNetworkInfoParcels) {
  *aNetworkInfoParcels = mNetworkInfos;
  return Status::ok();
}

void ConnectivityInheritServer::updateActiveNetworkInfo(
    NetworkInfoParcel& aNetworkInfoParcel) {
  mActiveNetworkInfo = aNetworkInfoParcel;
  for (auto& listenerMap : mConnectivityInheritListenerMap) {
    listenerMap.first->onActiveNetworkChanged(aNetworkInfoParcel);
  }
}

void ConnectivityInheritServer::updateNetworkInfo(
    NetworkInfoParcel& aNetworkInfoParcel) {
  // Update NetworkInfos cache.
  bool found = false;
  for (uint32_t i = 0; i < mNetworkInfos.size(); i++) {
    if (mNetworkInfos[i].type == aNetworkInfoParcel.type &&
        mNetworkInfos[i].name == aNetworkInfoParcel.name) {
      // Replace by new status.
      found = true;
      mNetworkInfos[i] = aNetworkInfoParcel;
      break;
    }
  }
  if (!found) {
    mNetworkInfos.push_back(aNetworkInfoParcel);
  }

  for (auto& listenerMap : mConnectivityInheritListenerMap) {
    listenerMap.first->onNetworkChanged(aNetworkInfoParcel);
  }
}

void ConnectivityInheritServer::InitNetworkInfo(
    NetworkInfoParcel& aNetworkInfo) {
  aNetworkInfo.name.clear();
  aNetworkInfo.netId = 0;
  aNetworkInfo.state = IConnectivity::NETWORK_STATE_UNKNOWN;
  aNetworkInfo.type = IConnectivity::NETWORK_TYPE_UNKNOWN;
  aNetworkInfo.prefixLengths.clear();
  aNetworkInfo.ips.clear();
  aNetworkInfo.gateways.clear();
  aNetworkInfo.dnses.clear();
}

// Let's ignore below functions to test inherit abilities.
#if 0
// Tethering function
// Captive portal function
#endif
