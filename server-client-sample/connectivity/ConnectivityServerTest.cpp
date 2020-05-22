/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IInterface.h>
#include "ConnectivityServerTest.h"
#include "b2g/connectivity/BnConnectivity.h"

#define KAIOS_CON_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_ConnectivityServer", ##args)

using android::ProcessState;
using android::sp;
using android::binder::Status;
using b2g::connectivity::IConnectivityEventListener;
using b2g::connectivity::NetworkInfoParcel;

ConnectivityServerTest::ConnectivityServerTest() {
  InitNetworkInfo(mActiveNetworkInfo);
  android::defaultServiceManager()->addService(
      android::String16(getServiceName()), this);
  sp<ProcessState> process(ProcessState::self());
  process->startThreadPool();
}

Status ConnectivityServerTest::isAlive(bool* aLive) {
  *aLive = true;
  return Status::ok();
}

Status ConnectivityServerTest::registerEventListener(
    const sp<IConnectivityEventListener>& listener) {
  std::lock_guard lock(mNetworkEventMutex);

  class DeathRecipient : public android::IBinder::DeathRecipient {
   public:
    DeathRecipient(ConnectivityServerTest* connectivityServerTest,
                   android::sp<IConnectivityEventListener> listener)
        : mConnectivityServerTest(connectivityServerTest),
          mListener(std::move(listener)) {}
    ~DeathRecipient() override = default;
    void binderDied(const android::wp<android::IBinder>& /* who */) override {
      KAIOS_CON_DEBUG("Client is dead, remove listener");
      mConnectivityServerTest->unregisterEventListener(mListener);
    }

   private:
    ConnectivityServerTest* mConnectivityServerTest;
    android::sp<IConnectivityEventListener> mListener;
  };
  android::sp<android::IBinder::DeathRecipient> deathRecipient =
      new DeathRecipient(this, listener);

  android::IInterface::asBinder(listener)->linkToDeath(deathRecipient);

  mConnectivityListenerTestMap.insert({listener, deathRecipient});
  return Status::ok();
}

Status ConnectivityServerTest::unregisterEventListener(
    const sp<IConnectivityEventListener>& listener) {
  std::lock_guard lock(mNetworkEventMutex);
  mConnectivityListenerTestMap.erase(listener);
  return Status::ok();
}

Status ConnectivityServerTest::getActiveNetworkInfo(
    NetworkInfoParcel* aNetworkInfoParcel) {
  *aNetworkInfoParcel = mActiveNetworkInfo;
  return Status::ok();
}

Status ConnectivityServerTest::getNetworkInfos(
    std::vector<NetworkInfoParcel>* aNetworkInfoParcels) {
  *aNetworkInfoParcels = mNetworkInfos;
  return Status::ok();
}

void ConnectivityServerTest::updateActiveNetworkInfo(
    NetworkInfoParcel& aNetworkInfoParcel) {
  mActiveNetworkInfo = aNetworkInfoParcel;
  for (auto& listenerMap : mConnectivityListenerTestMap) {
    listenerMap.first->onActiveNetworkChanged(aNetworkInfoParcel);
  }
}

void ConnectivityServerTest::updateNetworkInfo(
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

  for (auto& listenerMap : mConnectivityListenerTestMap) {
    listenerMap.first->onNetworkChanged(aNetworkInfoParcel);
  }
}

void ConnectivityServerTest::InitNetworkInfo(NetworkInfoParcel& aNetworkInfo) {
  aNetworkInfo.name.clear();
  aNetworkInfo.state = IConnectivity::NETWORK_STATE_UNKNOWN;
  aNetworkInfo.type = IConnectivity::NETWORK_TYPE_UNKNOWN;
  aNetworkInfo.prefixLengths.clear();
  aNetworkInfo.ips.clear();
  aNetworkInfo.gateways.clear();
  aNetworkInfo.dnses.clear();
}
