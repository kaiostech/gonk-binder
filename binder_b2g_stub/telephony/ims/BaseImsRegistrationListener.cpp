/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <b2g_stub/telephony/ims/BaseImsRegistrationListener.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ims::ImsReasonInfoParcelable;

namespace b2g_stub {
namespace telephony {
namespace ims {

// IImsRegistrationListener.
Status BaseImsRegistrationListener::onRegistered(int32_t imsRadioTech) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsRegistrationListener::onRegistering(int32_t imsRadioTech) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsRegistrationListener::onDeregistered(int32_t reasonInfo, const ::std::string& extraMessage) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsRegistrationListener::onTechnologyChangeFailed(
    int32_t imsRadioTech, const ImsReasonInfoParcelable& reason) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub
