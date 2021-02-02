/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_REGISTRATION_H_
#define _BASE_IMS_REGISTRATION_H_

#include <b2g/telephony/ims/BnImsRegistration.h>

namespace kaios_binder {
namespace telephony {
namespace ims {

class BaseImsRegistration : public b2g::telephony::ims::BnImsRegistration {
 public:
  // IImsRegistration.
  android::binder::Status getRegistrationTechnology(
      int32_t* _aidl_return) override;
  android::binder::Status addListener(
      const ::android::sp<::b2g::telephony::ims::IImsRegistrationListener>&
          listener) override;
  android::binder::Status removeListener(
      const ::android::sp<::b2g::telephony::ims::IImsRegistrationListener>&
          listener) override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder

#endif  // _BASE_IMS_REGISTRATION_H_
