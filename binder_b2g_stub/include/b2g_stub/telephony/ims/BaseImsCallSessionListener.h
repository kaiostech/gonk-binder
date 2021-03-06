/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_CALL_SESSION_LISTENER_H_
#define _BASE_IMS_CALL_SESSION_LISTENER_H_

#include <b2g/telephony/ims/BnImsCallSessionListener.h>

namespace b2g_stub {
namespace telephony {
namespace ims {

class BaseImsCallSessionListener
    : public b2g::telephony::ims::BnImsCallSessionListener {
 public:
  // IImsCallSessionListener.
  android::binder::Status onCallSessionProgressing(
      const ::b2g::telephony::ims::ImsStreamMediaProfileParcelable&
          mediaProfile) override;
  android::binder::Status onCallSessionStarted(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile) override;
  android::binder::Status onCallSessionStartFailed(
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reasonInfo)
      override;
  android::binder::Status onCallSessionTerminated(
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reasonInfo)
      override;
  android::binder::Status onCallSessionHeld(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile) override;
  android::binder::Status onCallSessionHoldFailed(
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reasonInfo)
      override;
  android::binder::Status onCallSessionResumed(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile) override;
  android::binder::Status onCallSessionResumeFailed(
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reasonInfo)
      override;
  android::binder::Status onCallSessionHoldReceived(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile) override;
  android::binder::Status onCallSessionResumeReceived(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile) override;
  android::binder::Status onCallSessionUpdated(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile) override;
  android::binder::Status onCallSessionRttModifyRequestReceived(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& toProfile)
      override;
  android::binder::Status onCallSessionRttModifyResponseReceived(
      int32_t status) override;
  android::binder::Status onCallSessionRttMessageReceived(
      const ::std::string& rttMessage) override;
  android::binder::Status onCallSessionRttAudioIndicatorChanged(
      const ::b2g::telephony::ims::ImsStreamMediaProfileParcelable&
          mediaProfile) override;
  android::binder::Status onCallSessionSuppServiceReceived(
      const ::b2g::telephony::ims::ImsSuppServiceNotificationParcelable&
          suppSrvNotification) override;
  android::binder::Status onCallSessionTtyModeReceived(int32_t mode) override;
  android::binder::Status onCallSessionMayHandover(int32_t srcTech,
                                                   int32_t targetTech) override;
  android::binder::Status onCallSessionHandover(int32_t srcTech,
                                                int32_t targetTech) override;
  android::binder::Status onCallSessionHandoverFailed(
      int32_t srcTech, int32_t targetTech,
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reasonInfo)
      override;
  android::binder::Status onCallSessionConferenceStateUpdated(
      const ::std::vector<
          ::b2g::telephony::ims::ImsConferenceParticipantParcelable>&
          participants) override;
  android::binder::Status onCallSessionRemoveParticipantsRequestDelivered()
      override;
  android::binder::Status onCallSessionRemoveParticipantsRequestFailed(
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reasonInfo)
      override;
  android::binder::Status onCallSessionTransferred() override;
  android::binder::Status onCallSessionTransferFailed(
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reasonInfo)
      override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub

#endif  // _BASE_IMS_CALL_SESSION_LISTENER_H_
