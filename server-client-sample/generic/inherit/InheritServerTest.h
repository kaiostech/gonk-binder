/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _INHERIT_SERVER_TEST_H_
#define _INHERIT_SERVER_TEST_H_

#include <binder/BinderService.h>
#include <mutex>
// TODO: REWRITE_BY_YOURSELF
#include <b2g_stub/connectivity/BaseConnectivity.h>

class InheritServerTest : public android::BinderService<InheritServerTest>,
                          // TODO: REWRITE_BY_YOURSELF
                          public b2g_stub::connectivity::BaseConnectivity {
 public:
  InheritServerTest();
  ~InheritServerTest() = default;

  static char const* getServiceName() { return "InheritServerTest"; }

  // TODO: REWRITE_BY_YOURSELF_START
  android::binder::Status isAlive(bool* aLive) override;

  // Network function.
  using InheritListenerMap =
      std::map<const android::sp<b2g::connectivity::IConnectivityEventListener>,
               const android::sp<android::IBinder::DeathRecipient>>;

  android::binder::Status addEventListener(
      const android::sp<b2g::connectivity::IConnectivityEventListener>&
          listener) override;

  android::binder::Status removeEventListener(
      const android::sp<b2g::connectivity::IConnectivityEventListener>&
          listener) override;

  void updateActiveNetworkInfo(
      b2g::connectivity::NetworkInfoParcel& aNetworkInfoParcel);

  void updateNetworkInfo(
      b2g::connectivity::NetworkInfoParcel& aNetworkInfoParcel);

  // Let's ignore below functions to test inherit abilities.
#if 0
  android::binder::Status getActiveNetworkInfo(
      b2g::connectivity::NetworkInfoParcel* aNetworkInfoParcel) override;

  android::binder::Status getNetworkInfos(
      std::vector<b2g::connectivity::NetworkInfoParcel>* aNetworkInfoParcels)
      override;

  // Tethering function.
  // Captive portal function.
#endif

 private:
  // Network information.
  std::mutex mNetworkEventMutex;
  InheritListenerMap mInheritListenerMap;
  b2g::connectivity::NetworkInfoParcel mActiveNetworkInfo;
  std::vector<b2g::connectivity::NetworkInfoParcel> mNetworkInfos;
  void InitNetworkInfo(b2g::connectivity::NetworkInfoParcel& networkInfo);
  // TODO: REWRITE_BY_YOURSELF_END
};

#endif  // _INHERIT_SERVER_TEST_H_
