/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _CONNECTIVITY_SERVER_TEST_H_
#define _CONNECTIVITY_SERVER_TEST_H_

#include <mutex>
#include <binder/BinderService.h>
#include <b2g/connectivity/BnConnectivity.h>

class ConnectivityServerTest
    : public android::BinderService<ConnectivityServerTest>,
      public b2g::connectivity::BnConnectivity {
 public:
  ConnectivityServerTest();
  ~ConnectivityServerTest() = default;

  using ConnectivityListenerTestMap =
      std::map<const android::sp<b2g::connectivity::IConnectivityEventListener>,
               const android::sp<android::IBinder::DeathRecipient>>;

  static char const* getServiceName() { return "connectivityServerTest"; }

  android::binder::Status isAlive(bool* aLive) override;

  android::status_t dump(
      int fd, const android::Vector<android::String16>& args) override {
    return android::NO_ERROR;
  }

  android::binder::Status registerEventListener(
      const android::sp<b2g::connectivity::IConnectivityEventListener>&
          listener) override;

  android::binder::Status unregisterEventListener(
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

 private:
  ConnectivityListenerTestMap mConnectivityListenerTestMap;

  std::mutex mNetworkEventMutex;
  b2g::connectivity::NetworkInfoParcel mActiveNetworkInfo;
  std::vector<b2g::connectivity::NetworkInfoParcel> mNetworkInfos;
  void InitNetworkInfo(b2g::connectivity::NetworkInfoParcel& networkInfo);
};

#endif  // _CONNECTIVITY_SERVER_TEST_H_
