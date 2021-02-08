/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include "ServerTest.h"
#include <binder/IInterface.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>

#define KAIOS_SERVER_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_ConnectivityServer", ##args)

using android::ProcessState;
using android::sp;
using android::binder::Status;

// TODO: REWRITE_BY_YOURSELF_START
#include "b2g/connectivity/BnConnectivity.h"
using b2g::connectivity::CaptivePortalLandingParcel;
using b2g::connectivity::ICaptivePortalLandingListener;
using b2g::connectivity::IConnectivityEventListener;
using b2g::connectivity::ITetheringStatusListener;
using b2g::connectivity::NetworkInfoParcel;
using b2g::connectivity::TetheringStatusParcel;

// Helper function.
void ServerTest::InitNetworkInfo(NetworkInfoParcel& aNetworkInfo) {
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

ServerTest::ServerTest() {
  // TODO: REWRITE_BY_YOURSELF
  InitNetworkInfo(mActiveNetworkInfo);
  android::defaultServiceManager()->addService(
      android::String16(getServiceName()), this);
  sp<ProcessState> process(ProcessState::self());
  process->startThreadPool();
}

// TODO: REWRITE_BY_YOURSELF_START
Status ServerTest::isAlive(bool* aLive) {
  *aLive = true;
  return Status::ok();
}

// Network function
Status ServerTest::addEventListener(
    const sp<IConnectivityEventListener>& listener) {
  std::lock_guard lock(mNetworkEventMutex);

  class DeathRecipient : public android::IBinder::DeathRecipient {
   public:
    DeathRecipient(ServerTest* serverTest,
                   sp<IConnectivityEventListener> listener)
        : mServerTest(serverTest), mListener(std::move(listener)) {}
    ~DeathRecipient() override = default;
    void binderDied(const android::wp<android::IBinder>& /* who */) override {
      KAIOS_SERVER_DEBUG("Client is dead, remove listener");
      mServerTest->removeEventListener(mListener);
    }

   private:
    ServerTest* mServerTest;
    sp<IConnectivityEventListener> mListener;
  };
  sp<android::IBinder::DeathRecipient> deathRecipient =
      new DeathRecipient(this, listener);

  android::IInterface::asBinder(listener)->linkToDeath(deathRecipient);

  mListenerTestMap.insert({listener, deathRecipient});
  return Status::ok();
}

Status ServerTest::removeEventListener(
    const sp<IConnectivityEventListener>& listener) {
  std::lock_guard lock(mNetworkEventMutex);
  mListenerTestMap.erase(listener);
  return Status::ok();
}

Status ServerTest::getActiveNetworkInfo(NetworkInfoParcel* aNetworkInfoParcel) {
  *aNetworkInfoParcel = mActiveNetworkInfo;
  return Status::ok();
}

Status ServerTest::getNetworkInfos(
    std::vector<NetworkInfoParcel>* aNetworkInfoParcels) {
  *aNetworkInfoParcels = mNetworkInfos;
  return Status::ok();
}

void ServerTest::updateActiveNetworkInfo(
    NetworkInfoParcel& aNetworkInfoParcel) {
  mActiveNetworkInfo = aNetworkInfoParcel;
  for (auto& listenerMap : mListenerTestMap) {
    listenerMap.first->onActiveNetworkChanged(aNetworkInfoParcel);
  }
}

void ServerTest::updateNetworkInfo(NetworkInfoParcel& aNetworkInfoParcel) {
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

  for (auto& listenerMap : mListenerTestMap) {
    listenerMap.first->onNetworkChanged(aNetworkInfoParcel);
  }
}

// Tethering function
Status ServerTest::getTetheringStatus(
    TetheringStatusParcel* aTetheringStatusParcel) {
  *aTetheringStatusParcel = mTetheringStatusParcel;
  return Status::ok();
}

Status ServerTest::addTetheringStatusListener(
    const sp<ITetheringStatusListener>& listener) {
  std::lock_guard lock(mTetheringMutex);

  class DeathRecipient : public android::IBinder::DeathRecipient {
   public:
    DeathRecipient(ServerTest* serverTest,
                   sp<ITetheringStatusListener> listener)
        : mServerTest(serverTest), mListener(std::move(listener)) {}
    ~DeathRecipient() override = default;
    void binderDied(const android::wp<android::IBinder>& /* who */) override {
      KAIOS_SERVER_DEBUG("Client is dead, remove tethering listener");
      mServerTest->removeTetheringStatusListener(mListener);
    }

   private:
    ServerTest* mServerTest;
    sp<ITetheringStatusListener> mListener;
  };
  sp<android::IBinder::DeathRecipient> deathRecipient =
      new DeathRecipient(this, listener);

  android::IInterface::asBinder(listener)->linkToDeath(deathRecipient);

  mTetheringListenerTestMap.insert({listener, deathRecipient});

  return Status::ok();
}

Status ServerTest::removeTetheringStatusListener(
    const sp<ITetheringStatusListener>& listener) {
  std::lock_guard lock(mTetheringMutex);
  mTetheringListenerTestMap.erase(listener);
  return Status::ok();
}

void ServerTest::updateTetheringStatus(
    TetheringStatusParcel& aTetheringStatusParcel) {
  mTetheringStatusParcel = aTetheringStatusParcel;
  for (auto& listenerMap : mTetheringListenerTestMap) {
    listenerMap.first->onTetheringStatusChanged(aTetheringStatusParcel);
  }
}

// Captive portal function
Status ServerTest::getCaptivePortalLandings(
    std::vector<CaptivePortalLandingParcel>* aCaptivePortalLandings) {
  *aCaptivePortalLandings = mCaptivePortalLandings;
  return Status::ok();
}

Status ServerTest::addCaptivePortalLandingListener(
    const sp<ICaptivePortalLandingListener>& listener) {
  std::lock_guard lock(mCaptivePortalMutex);

  class DeathRecipient : public android::IBinder::DeathRecipient {
   public:
    DeathRecipient(ServerTest* serverTest,
                   sp<ICaptivePortalLandingListener> listener)
        : mServerTest(serverTest), mListener(std::move(listener)) {}
    ~DeathRecipient() override = default;
    void binderDied(const android::wp<android::IBinder>& /* who */) override {
      KAIOS_SERVER_DEBUG("Client is dead, remove captive portal listener");
      mServerTest->removeCaptivePortalLandingListener(mListener);
    }

   private:
    ServerTest* mServerTest;
    sp<ICaptivePortalLandingListener> mListener;
  };
  sp<android::IBinder::DeathRecipient> deathRecipient =
      new DeathRecipient(this, listener);

  android::IInterface::asBinder(listener)->linkToDeath(deathRecipient);

  mCaptivePortalListenerTestMap.insert({listener, deathRecipient});

  return Status::ok();
}

Status ServerTest::removeCaptivePortalLandingListener(
    const sp<ICaptivePortalLandingListener>& listener) {
  std::lock_guard lock(mCaptivePortalMutex);
  mCaptivePortalListenerTestMap.erase(listener);
  return Status::ok();
}

void ServerTest::updateCaptivePortal(
    CaptivePortalLandingParcel& aCaptivePortalLandingParcel) {
  // Update captive portal status.
  bool found = false;
  for (uint32_t i = 0; i < mCaptivePortalLandings.size(); i++) {
    if (mCaptivePortalLandings[i].networkType ==
            aCaptivePortalLandingParcel.networkType &&
        mCaptivePortalLandings[i].landing ==
            aCaptivePortalLandingParcel.landing) {
      // Replace by new status.
      found = true;
      mCaptivePortalLandings[i] = aCaptivePortalLandingParcel;
      break;
    }
  }
  if (!found) {
    mCaptivePortalLandings.push_back(aCaptivePortalLandingParcel);
  }

  for (auto& listenerMap : mCaptivePortalListenerTestMap) {
    listenerMap.first->onCaptivePortalLandingChanged(
        aCaptivePortalLandingParcel);
  }
}
// TODO: REWRITE_BY_YOURSELF_END
