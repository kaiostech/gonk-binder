/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <kaios_binder/telephony/ims/BaseImsRegistration.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ims::IImsRegistrationListener;

namespace kaios_binder {
namespace telephony {
namespace ims {

// IImsRegistration.
Status BaseImsRegistration::getRegistrationTechnology(int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsRegistration::addListener(
    const sp<IImsRegistrationListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsRegistration::removeListener(
    const sp<IImsRegistrationListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder
