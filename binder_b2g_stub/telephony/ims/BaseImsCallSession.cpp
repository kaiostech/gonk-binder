/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <b2g_stub/telephony/ims/BaseImsCallSession.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ims::IImsCallSession;
using b2g::telephony::ims::IImsCallSessionListener;
using b2g::telephony::ims::IImsDtmfCallback;
using b2g::telephony::ims::ImsCallProfileParcelable;
using b2g::telephony::ims::ImsStreamMediaProfileParcelable;

namespace b2g_stub {
namespace telephony {
namespace ims {

// IImsCallSession.
Status BaseImsCallSession::close() {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::getCallId(::std::string* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::getCallProfile(
    ImsCallProfileParcelable* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::getLocalCallProfile(
    ImsCallProfileParcelable* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::getRemoteCallProfile(
    ImsCallProfileParcelable* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::getState(int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::setListener(
    const sp<IImsCallSessionListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::start(const ::std::string& callee,
                                 const ImsCallProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::accept(
    int32_t callType, const ImsStreamMediaProfileParcelable& profile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::reject(int32_t reason) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::terminate(int32_t reason) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::hold() {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::resume() {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::sendDtmf(char16_t c,
                                    const sp<IImsDtmfCallback>& callback) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::startDtmf(char16_t c) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::stopDtmf() {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::sendRttModifyRequest(
    const ImsCallProfileParcelable& toProfile) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::sendRttModifyResponse(bool status) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::sendRttMessage(const ::std::string& rttMessage) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::isMultiparty(bool* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::removeParticipants(
    const ::std::vector<::std::string>& participants) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsCallSession::consultativeTransfer(
    const sp<IImsCallSession>& toSession) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub
