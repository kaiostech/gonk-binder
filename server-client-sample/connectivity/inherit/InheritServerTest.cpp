/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include "InheritServerTest.h"
#include <binder/IInterface.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>

#define KAIOS_SERVER_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_ConnectivityServer", ##args)

using android::ProcessState;
using android::sp;
using android::binder::Status;

// TODO: REWRITE_BY_YOURSELF_START
using b2g::connectivity::IConnectivityEventListener;
using b2g::connectivity::NetworkInfoParcel;
// TODO: REWRITE_BY_YOURSELF_END

InheritServerTest::InheritServerTest() {
  // TODO: REWRITE_BY_YOURSELF
  InitNetworkInfo(mActiveNetworkInfo);
  android::defaultServiceManager()->addService(
      android::String16(getServiceName()), this);
  sp<ProcessState> process(ProcessState::self());
  process->startThreadPool();
}

Status InheritServerTest::isAlive(bool* aLive) {
  *aLive = true;
  return Status::ok();
}

// Network function
Status InheritServerTest::addEventListener(
    const sp<IConnectivityEventListener>& listener) {
  std::lock_guard lock(mNetworkEventMutex);

  class DeathRecipient : public android::IBinder::DeathRecipient {
   public:
    DeathRecipient(InheritServerTest* inheritServerTest,
                   sp<IConnectivityEventListener> listener)
        : mInheritServerTest(inheritServerTest),
          mListener(std::move(listener)) {}
    ~DeathRecipient() override = default;
    void binderDied(const android::wp<android::IBinder>& /* who */) override {
      KAIOS_SERVER_DEBUG("Client is dead, remove listener");
      mInheritServerTest->removeEventListener(mListener);
    }

   private:
    InheritServerTest* mInheritServerTest;
    sp<IConnectivityEventListener> mListener;
  };
  sp<android::IBinder::DeathRecipient> deathRecipient =
      new DeathRecipient(this, listener);

  android::IInterface::asBinder(listener)->linkToDeath(deathRecipient);

  mInheritListenerMap.insert({listener, deathRecipient});
  return Status::ok();
}

Status InheritServerTest::removeEventListener(
    const sp<IConnectivityEventListener>& listener) {
  std::lock_guard lock(mNetworkEventMutex);
  mInheritListenerMap.erase(listener);
  return Status::ok();
}

Status InheritServerTest::getActiveNetworkInfo(
    NetworkInfoParcel* aNetworkInfoParcel) {
  *aNetworkInfoParcel = mActiveNetworkInfo;
  return Status::ok();
}

Status InheritServerTest::getNetworkInfos(
    std::vector<NetworkInfoParcel>* aNetworkInfoParcels) {
  *aNetworkInfoParcels = mNetworkInfos;
  return Status::ok();
}

void InheritServerTest::updateActiveNetworkInfo(
    NetworkInfoParcel& aNetworkInfoParcel) {
  mActiveNetworkInfo = aNetworkInfoParcel;
  for (auto& listenerMap : mInheritListenerMap) {
    listenerMap.first->onActiveNetworkChanged(aNetworkInfoParcel);
  }
}

void InheritServerTest::updateNetworkInfo(
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

  for (auto& listenerMap : mInheritListenerMap) {
    listenerMap.first->onNetworkChanged(aNetworkInfoParcel);
  }
}

void InheritServerTest::InitNetworkInfo(NetworkInfoParcel& aNetworkInfo) {
  aNetworkInfo.name.clear();
  aNetworkInfo.netId = 0;
  aNetworkInfo.state = IConnectivity::NETWORK_STATE_UNKNOWN;
  aNetworkInfo.type = IConnectivity::NETWORK_TYPE_UNKNOWN;
  aNetworkInfo.prefixLengths.clear();
  aNetworkInfo.ips.clear();
  aNetworkInfo.gateways.clear();
  aNetworkInfo.dnses.clear();
}
// TODO: REWRITE_BY_YOURSELF_END

// Let's ignore below functions to test inherit abilities.
#if 0
// Tethering function
// Captive portal function
#endif
