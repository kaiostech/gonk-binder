/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_REGISTRATION_LISTENER_H_
#define _BASE_IMS_REGISTRATION_LISTENER_H_

#include <b2g/telephony/ims/BnImsRegistrationListener.h>

namespace kaios_binder {
namespace telephony {
namespace ims {

class BaseImsRegistrationListener
    : public b2g::telephony::ims::BnImsRegistrationListener {
 public:
  // IImsRegistrationListener.
  android::binder::Status onRegistered(int32_t imsRadioTech) override;
  android::binder::Status onRegistering(int32_t imsRadioTech) override;
  android::binder::Status onDeregistered(int32_t reasonInfo) override;
  android::binder::Status onTechnologyChangeFailed(
      int32_t imsRadioTech,
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reason) override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder

#endif  // _BASE_IMS_REGISTRATION_LISTENER_H_
