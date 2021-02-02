/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <kaios_binder/telephony/ims/BaseImsCallSessionListener.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ims::ImsCallProfileParcelable;
using b2g::telephony::ims::ImsConferenceParticipantParcelable;
using b2g::telephony::ims::ImsReasonInfoParcelable;
using b2g::telephony::ims::ImsStreamMediaProfileParcelable;
using b2g::telephony::ims::ImsSuppServiceNotificationParcelable;

namespace kaios_binder {
namespace telephony {
namespace ims {

// IImsCallSessionListener.
Status BaseImsCallSessionListener::onCallSessionProgressing(
    const ImsStreamMediaProfileParcelable& mediaProfile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionStarted(
    const ImsCallProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionStartFailed(
    const ImsReasonInfoParcelable& reasonInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionTerminated(
    const ImsReasonInfoParcelable& reasonInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionHeld(
    const ImsCallProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionHoldFailed(
    const ImsReasonInfoParcelable& reasonInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionResumed(
    const ImsCallProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionResumeFailed(
    const ImsReasonInfoParcelable& reasonInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionHoldReceived(
    const ImsCallProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionResumeReceived(
    const ImsCallProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionUpdated(
    const ImsCallProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionRttModifyRequestReceived(
    const ImsCallProfileParcelable& toProfile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionRttModifyResponseReceived(
    int32_t status) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionRttMessageReceived(
    const ::std::string& rttMessage) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionRttAudioIndicatorChanged(
    const ImsStreamMediaProfileParcelable& mediaProfile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionSuppServiceReceived(
    const ImsSuppServiceNotificationParcelable& suppSrvNotification) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionTtyModeReceived(int32_t mode) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionMayHandover(
    int32_t srcTech, int32_t targetTech) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionHandover(int32_t srcTech,
                                                         int32_t targetTech) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionHandoverFailed(
    int32_t srcTech, int32_t targetTech,
    const ImsReasonInfoParcelable& reasonInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionConferenceStateUpdated(
    const ::std::vector<ImsConferenceParticipantParcelable>& participants) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status
BaseImsCallSessionListener::onCallSessionRemoveParticipantsRequestDelivered() {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionRemoveParticipantsRequestFailed(
    const ImsReasonInfoParcelable& reasonInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionTransferred() {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSessionListener::onCallSessionTransferFailed(
    const ImsReasonInfoParcelable& reasonInfo) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder
