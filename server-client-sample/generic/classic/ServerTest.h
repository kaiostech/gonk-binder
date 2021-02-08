/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _SERVER_TEST_H_
#define _SERVER_TEST_H_

#include <binder/BinderService.h>
#include <mutex>
// TODO: REWRITE_BY_YOURSELF
#include <b2g/connectivity/BnConnectivity.h>

class ServerTest : public android::BinderService<ServerTest>,
                   // TODO: REWRITE_BY_YOURSELF
                   public b2g::connectivity::BnConnectivity {
 public:
  ServerTest();
  ~ServerTest() = default;

  static char const* getServiceName() { return "KaiOSServerTest"; }

  // TODO: REWRITE_BY_YOURSELF_START
  android::binder::Status isAlive(bool* aLive) override;

  // Network function.
  using ListenerTestMap =
      std::map<const android::sp<b2g::connectivity::IConnectivityEventListener>,
               const android::sp<android::IBinder::DeathRecipient>>;

  android::binder::Status addEventListener(
      const android::sp<b2g::connectivity::IConnectivityEventListener>&
          listener) override;

  android::binder::Status removeEventListener(
      const android::sp<b2g::connectivity::IConnectivityEventListener>&
          listener) override;

  android::binder::Status getActiveNetworkInfo(
      b2g::connectivity::NetworkInfoParcel* aNetworkInfoParcel) override;

  android::binder::Status getNetworkInfos(
      std::vector<b2g::connectivity::NetworkInfoParcel>* aNetworkInfoParcels)
      override;

  void updateActiveNetworkInfo(
      b2g::connectivity::NetworkInfoParcel& aNetworkInfoParcel);

  void updateNetworkInfo(
      b2g::connectivity::NetworkInfoParcel& aNetworkInfoParcel);

  // Tethering function.
  android::binder::Status getTetheringStatus(
      b2g::connectivity::TetheringStatusParcel* aTetheringStatusParcel)
      override {
    return android::binder::Status::ok();
  }

  android::binder::Status addTetheringStatusListener(
      const android::sp<b2g::connectivity::ITetheringStatusListener>& listener)
      override {
    return android::binder::Status::ok();
  }

  android::binder::Status removeTetheringStatusListener(
      const android::sp<b2g::connectivity::ITetheringStatusListener>& listener)
      override {
    return android::binder::Status::ok();
  }

  // Captive portal function.
  android::binder::Status getCaptivePortalLandings(
      std::vector<b2g::connectivity::CaptivePortalLandingParcel>*
          aCaptivePortalLandings) override {
    return android::binder::Status::ok();
  }

  android::binder::Status addCaptivePortalLandingListener(
      const android::sp<b2g::connectivity::ICaptivePortalLandingListener>&
          listener) override {
    return android::binder::Status::ok();
  }

  android::binder::Status removeCaptivePortalLandingListener(
      const android::sp<b2g::connectivity::ICaptivePortalLandingListener>&
          listener) override {
    return android::binder::Status::ok();
  }

 private:
  // We only provide network information as example, dummy for
  // tethering/captiveportal.
  std::mutex mNetworkMutex;
  ListenerTestMap mListenerTestMap;
  b2g::connectivity::NetworkInfoParcel mActiveNetworkInfo;
  std::vector<b2g::connectivity::NetworkInfoParcel> mNetworkInfos;
  void InitNetworkInfo(b2g::connectivity::NetworkInfoParcel& networkInfo);
  // TODO: REWRITE_BY_YOURSELF_END
};

#endif  // _SERVER_TEST_H_
