/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_MMTEL_LISTENER_H_
#define _BASE_IMS_MMTEL_LISTENER_H_

#include <b2g/telephony/ims/BnImsMMTelListener.h>

namespace b2g_stub {
namespace telephony {
namespace ims {

class BaseImsMMTelListener : public b2g::telephony::ims::BnImsMMTelListener {
 public:
  // IImsMMTelListener.
  android::binder::Status onIncomingCall(
      const ::android::sp<::b2g::telephony::ims::IImsCallSession>& session,
      bool isUssd, bool isUnknown)
      override;
  android::binder::Status onVoiceMessageCountUpdate(int32_t count) override;
  android::binder::Status onCallSessionMergeStarted(
      const ::android::sp<::b2g::telephony::ims::IImsCallSession>& newSession,
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile) override;
  android::binder::Status onCallSessionMergeComplete(
      const ::android::sp<::b2g::telephony::ims::IImsCallSession>& newSession)
      override;
  android::binder::Status onCallSessionMergeFailed(
      const ::android::sp<::b2g::telephony::ims::IImsCallSession>& hostSession,
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reason) override;
  android::binder::Status onRejectedCall(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile,
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& reason) override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub

#endif  // _BASE_IMS_MMTEL_LISTENER_H_
