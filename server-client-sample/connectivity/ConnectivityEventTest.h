/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _CONNECTIVITY_EVENT_TEST_H_
#define _CONNECTIVITY_EVENT_TEST_H_

#include <binder/BinderService.h>
#include <b2g/connectivity/BnConnectivityEventListener.h>

class ConnectivityEventTest
    : public android::BinderService<ConnectivityEventTest>,
      public b2g::connectivity::BnConnectivityEventListener {
 public:
  ConnectivityEventTest();
  ~ConnectivityEventTest() = default;

  static char const* getServiceName() { return "connectivityEventTest"; }
  android::binder::Status onActiveNetworkChanged(
      const ::b2g::connectivity::NetworkInfoParcel& networkInfo) override;
  android::binder::Status onNetworkChanged(
      const ::b2g::connectivity::NetworkInfoParcel& networkInfo) override;
};

#endif  // _CONNECTIVITY_EVENT_TEST_H_
