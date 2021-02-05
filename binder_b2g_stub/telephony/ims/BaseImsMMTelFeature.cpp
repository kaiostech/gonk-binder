/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <b2g_stub/telephony/ims/BaseImsMMTelFeature.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ims::CapabilityChangeRequestParcelable;
using b2g::telephony::ims::IImsCallSession;
using b2g::telephony::ims::IImsCapabilityCallback;
using b2g::telephony::ims::IImsCapabilityListener;
using b2g::telephony::ims::IImsMMTelListener;
using b2g::telephony::ims::IImsSmsListener;
using b2g::telephony::ims::IImsTtyCallback;
using b2g::telephony::ims::IImsUt;
using b2g::telephony::ims::ImsCallProfileParcelable;

namespace b2g_stub {
namespace telephony {
namespace ims {

// IImsMMTelFeature.
Status BaseImsMMTelFeature::getFeatureStatus(int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::changeCapabilities(
    const CapabilityChangeRequestParcelable& request,
    const sp<IImsCapabilityCallback>& callback) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::getCapability(int32_t capability, int32_t radioTech,
                                          bool* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::addCapabilityListener(
    const sp<IImsCapabilityListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::removeCapabilityListener(
    const sp<IImsCapabilityListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::getUtInterface(sp<IImsUt>* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::setListener(const sp<IImsMMTelListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::createCallSession(
    const ImsCallProfileParcelable& profile,
    sp<IImsCallSession>* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::setSmsListener(
    const sp<IImsSmsListener>& smsListener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::sendSms(int32_t token, int32_t messageRef,
                                    const ::std::string& format,
                                    const ::std::string& smsc, bool isRetry,
                                    const ::std::vector<uint8_t>& pdu) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::acknowledgeSms(int32_t token, int32_t messageRef,
                                           int32_t result) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::acknowledgeSmsReport(int32_t token,
                                                 int32_t messageRef,
                                                 int32_t result) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::getSmsFormat(::std::string* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::setUiTtyMode(int32_t uiTtyMode,
                                         const sp<IImsTtyCallback>& callback) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsMMTelFeature::merge(const sp<IImsCallSession>& host,
                                  const sp<IImsCallSession>& peer) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub
