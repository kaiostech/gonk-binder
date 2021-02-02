/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_UT_H_
#define _BASE_IMS_UT_H_

#include <b2g/telephony/ims/BnImsUt.h>

namespace kaios_binder {
namespace telephony {
namespace ims {

class BaseImsUt : public b2g::telephony::ims::BnImsUt {
 public:
  // IImsUt.
  android::binder::Status setCallback(
      const ::android::sp<::b2g::telephony::ims::IImsUtCallback>& callback)
      override;
  android::binder::Status queryCallForward(int32_t condition,
                                           const ::std::string& number,
                                           int32_t* _aidl_return) override;
  android::binder::Status updateCallForward(int32_t action, int32_t condition,
                                            const ::std::string& number,
                                            int32_t serviceClass,
                                            int32_t timeSeconds,
                                            int32_t* _aidl_return) override;
  android::binder::Status queryCallBarring(int32_t cbType, int32_t serviceClass,
                                           int32_t* _aidl_return) override;
  android::binder::Status updateCallBarring(
      int32_t cbType, int32_t action,
      const ::std::vector<::std::string>& barrList, int32_t serviceClass,
      const ::std::string& password, int32_t* _aidl_return) override;
  android::binder::Status queryCallWaiting(int32_t* _aidl_return) override;
  android::binder::Status updateCallWaiting(bool enable, int32_t serviceClass,
                                            int32_t* _aidl_return) override;
  android::binder::Status queryCLIR(int32_t* _aidl_return) override;
  android::binder::Status updateCLIR(int32_t clirMode,
                                     int32_t* _aidl_return) override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder

#endif  // _BASE_IMS_UT_H_
