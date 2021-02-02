/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <kaios_binder/telephony/ims/BaseImsUtCallback.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ims::ImsCallForwardInfoParcelable;
using b2g::telephony::ims::ImsClirResponseParcelable;
using b2g::telephony::ims::ImsReasonInfoParcelable;
using b2g::telephony::ims::ImsSsInfoParcelable;

namespace kaios_binder {
namespace telephony {
namespace ims {

// IImsUtCallback.
Status BaseImsUtCallback::onCallForwardQueried(
    int32_t id, const ::std::vector<ImsCallForwardInfoParcelable>& cfInfos) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUtCallback::onUtConfigurationUpdated(int32_t id) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUtCallback::onUtConfigurationUpdateFailed(
    int32_t id, const ImsReasonInfoParcelable& error) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUtCallback::onCallBarringQueried(
    int32_t id, const ImsSsInfoParcelable& cbInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUtCallback::onCallWaitingQueried(
    int32_t id, const ImsSsInfoParcelable& cwInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUtCallback::utConfigurationQueryFailed(
    int32_t id, const ImsReasonInfoParcelable& error) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUtCallback::onClirQueried(
    int32_t id, const ImsClirResponseParcelable& clirStatus) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder
