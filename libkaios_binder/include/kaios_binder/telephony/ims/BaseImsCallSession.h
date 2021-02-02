/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_CALL_SESSION_H_
#define _BASE_IMS_CALL_SESSION_H_

#include <b2g/telephony/ims/BnImsCallSession.h>

namespace kaios_binder {
namespace telephony {
namespace ims {

class BaseImsCallSession : public b2g::telephony::ims::BnImsCallSession {
 public:
  // IImsCallSession.
  android::binder::Status close() override;
  android::binder::Status getCallId(::std::string* _aidl_return) override;
  android::binder::Status getCallProfile(
      ::b2g::telephony::ims::ImsCallProfileParcelable* _aidl_return) override;
  android::binder::Status getLocalCallProfile(
      ::b2g::telephony::ims::ImsCallProfileParcelable* _aidl_return) override;
  android::binder::Status getRemoteCallProfile(
      ::b2g::telephony::ims::ImsCallProfileParcelable* _aidl_return) override;
  android::binder::Status getState(int32_t* _aidl_return) override;
  android::binder::Status setListener(
      const ::android::sp<::b2g::telephony::ims::IImsCallSessionListener>&
          listener) override;
  android::binder::Status start(
      const ::std::string& callee,
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile) override;
  android::binder::Status accept(
      int32_t callType,
      const ::b2g::telephony::ims::ImsStreamMediaProfileParcelable& profile)
      override;
  android::binder::Status reject(int32_t reason) override;
  android::binder::Status terminate(int32_t reason) override;
  android::binder::Status hold() override;
  android::binder::Status resume() override;
  android::binder::Status sendDtmf(
      char16_t c,
      const ::android::sp<::b2g::telephony::ims::IImsDtmfCallback>& callback)
      override;
  android::binder::Status startDtmf(char16_t c) override;
  android::binder::Status stopDtmf() override;
  android::binder::Status sendRttModifyRequest(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& toProfile)
      override;
  android::binder::Status sendRttModifyResponse(bool status) override;
  android::binder::Status sendRttMessage(
      const ::std::string& rttMessage) override;
  android::binder::Status isMultiparty(bool* _aidl_return) override;
  android::binder::Status removeParticipants(
      const ::std::vector<::std::string>& participants) override;
  android::binder::Status consultativeTransfer(
      const ::android::sp<::b2g::telephony::ims::IImsCallSession>& toSession)
      override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder

#endif  // _BASE_IMS_CALL_SESSION_H_
