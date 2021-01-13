/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _WIFI_LISTENER_TEST_H_
#define _WIFI_LISTENER_TEST_H_

#include <b2g/connectivity/BnWifiStateListener.h>
#include <binder/BinderService.h>

class WifiListenerTest
    : public android::BinderService<WifiListenerTest>,
      public b2g::connectivity::BnWifiStateListener {
public:
  WifiListenerTest();
  ~WifiListenerTest() = default;

  static char const *getServiceName() { return "WifiListenerTest"; }
  android::binder::Status onWifiStateChanged(int32_t state) override;
};

#endif // _WIFI_LISTENER_TEST_H_
