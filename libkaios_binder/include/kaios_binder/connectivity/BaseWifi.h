/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_WIFI_H_
#define _BASE_WIFI_H_

#include <b2g/connectivity/BnWifi.h>

namespace kaios_binder {
namespace connectivity {

class BaseWifi : public b2g::connectivity::BnWifi {
 public:
  // IWifi.
  android::binder::Status getWifiState(int32_t* _aidl_return) override;

  android::binder::Status addWifiStateListener(
      const android::sp<b2g::connectivity::IWifiStateListener>& listener)
      override;

  android::binder::Status removeWifiStateListener(
      const android::sp<b2g::connectivity::IWifiStateListener>& listener)
      override;
};

}  // namespace connectivity
}  // namespace kaios_binder

#endif  // _BASE_WIFI_H_
