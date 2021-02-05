/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_ECBM_H_
#define _BASE_IMS_ECBM_H_

#include <b2g/telephony/ims/BnImsEcbm.h>

namespace b2g_stub {
namespace telephony {
namespace ims {

class BaseImsEcbm : public b2g::telephony::ims::BnImsEcbm {
 public:
  // IImsEcbm.
  android::binder::Status setListener(
      const ::android::sp<::b2g::telephony::ims::IImsEcbmListener>& listener)
      override;
  android::binder::Status exitEmergencyCallbackMode() override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub

#endif  // _BASE_IMS_ECBM_H_
