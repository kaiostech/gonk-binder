/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_DATACALL_H_
#define _BASE_DATACALL_H_

#include <b2g/telephony/data/BnDataCall.h>

namespace kaios_binder {
namespace telephony {
namespace data {

class BaseDataCall : public b2g::telephony::data::BnDataCall {
 public:
  // IDataCall.
  android::binder::Status setupDataCallByType(int32_t sreviceId,
                                              int32_t networkType) override;

  android::binder::Status deactivateDataCallByType(
      int32_t sreviceId, int32_t networkType) override;

  android::binder::Status getDefaultSlotId(int32_t* _aidl_return) override;

  android::binder::Status addEventListener(
      const android::sp<b2g::telephony::data::IDataCallEventListener>& listener)
      override;

  android::binder::Status removeEventListener(
      const android::sp<b2g::telephony::data::IDataCallEventListener>& listener)
      override;
};

}  // namespace data
}  // namespace telephony
}  // namespace kaios_binder

#endif  // _BASE_DATACALL_H_
