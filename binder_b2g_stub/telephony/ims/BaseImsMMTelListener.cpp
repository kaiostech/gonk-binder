/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <b2g_stub/telephony/ims/BaseImsMMTelListener.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ims::ImsCallProfileParcelable;
;
using b2g::telephony::ims::IImsCallSession;
using b2g::telephony::ims::ImsReasonInfoParcelable;

namespace b2g_stub {
namespace telephony {
namespace ims {

// IImsMMTelListener.
Status BaseImsMMTelListener::onIncomingCall(
    const sp<IImsCallSession>& session, bool isUssd, bool isUnknown) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelListener::onVoiceMessageCountUpdate(int32_t count) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelListener::onCallSessionMergeStarted(
    const sp<IImsCallSession>& newSession,
    const ImsCallProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelListener::onCallSessionMergeComplete(
    const sp<IImsCallSession>& newSession) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelListener::onCallSessionMergeFailed(
    const sp<IImsCallSession>& hostSession,
    const ImsReasonInfoParcelable& reason) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelListener::onRejectedCall(
    const ImsCallProfileParcelable& profile,
    const ImsReasonInfoParcelable& reason) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub
