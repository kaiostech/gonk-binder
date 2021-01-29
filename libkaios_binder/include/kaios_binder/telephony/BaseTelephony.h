/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_TELEPHONY_H_
#define _BASE_TELEPHONY_H_

#include <b2g/telephony/BnTelephony.h>

namespace kaios_binder {
namespace telephony {

class BaseTelephony : public b2g::telephony::BnTelephony {
 public:
  // ITelephony.
  android::binder::Status getSupportedRadioAccessFamily(
      int32_t slotId, int32_t* _aidl_return) override;

  android::binder::Status getPhoneCount(int32_t* _aidl_return) override;
};

}  // namespace telephony
}  // namespace kaios_binder

#endif  // _BASE_TELEPHONY_H_
