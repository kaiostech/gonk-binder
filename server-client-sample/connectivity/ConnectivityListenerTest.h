/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _CONNECTIVITY_LISTENER_TEST_H_
#define _CONNECTIVITY_LISTENER_TEST_H_

#include <b2g/connectivity/BnConnectivityEventListener.h>
#include <binder/BinderService.h>

class ConnectivityListenerTest
    : public android::BinderService<ConnectivityListenerTest>,
      public b2g::connectivity::BnConnectivityEventListener {
public:
  ConnectivityListenerTest();
  ~ConnectivityListenerTest() = default;

  static char const *getServiceName() { return "connectivityListenerTest"; }
  android::binder::Status onActiveNetworkChanged(
      const ::b2g::connectivity::NetworkInfoParcel &networkInfo) override;
  android::binder::Status onNetworkChanged(
      const ::b2g::connectivity::NetworkInfoParcel &networkInfo) override;
};

#endif // _CONNECTIVITY_LISTENER_TEST_H_
