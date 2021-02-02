/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_CONFIG_H_
#define _BASE_IMS_CONFIG_H_

#include <b2g/telephony/ims/BnImsConfig.h>

namespace kaios_binder {
namespace telephony {
namespace ims {

class BaseImsConfig : public b2g::telephony::ims::BnImsConfig {
 public:
  // IImsConfig.
  android::binder::Status queryConfigInt(
      int32_t item,
      const ::android::sp<::b2g::telephony::ims::IImsConfigCallback>& callback)
      override;
  android::binder::Status setConfigInt(
      int32_t item, int32_t value,
      const ::android::sp<::b2g::telephony::ims::IImsConfigCallback>& callback)
      override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder

#endif  // _BASE_IMS_CONFIG_H_
