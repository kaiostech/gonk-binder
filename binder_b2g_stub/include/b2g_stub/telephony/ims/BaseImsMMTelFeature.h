/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_MMTEL_FEATURE_H_
#define _BASE_IMS_MMTEL_FEATURE_H_

#include <b2g/telephony/ims/BnImsMMTelFeature.h>

namespace b2g_stub {
namespace telephony {
namespace ims {

class BaseImsMMTelFeature : public b2g::telephony::ims::BnImsMMTelFeature {
 public:
  // IImsMMTelFeature.
  android::binder::Status getFeatureStatus(int32_t* _aidl_return) override;
  android::binder::Status changeCapabilities(
      const ::b2g::telephony::ims::CapabilityChangeRequestParcelable& request,
      const ::android::sp<::b2g::telephony::ims::IImsCapabilityCallback>&
          callback) override;
  android::binder::Status getCapability(int32_t capability, int32_t radioTech,
                                        bool* _aidl_return) override;
  android::binder::Status addCapabilityListener(
      const ::android::sp<::b2g::telephony::ims::IImsCapabilityListener>&
          listener) override;
  android::binder::Status removeCapabilityListener(
      const ::android::sp<::b2g::telephony::ims::IImsCapabilityListener>&
          listener) override;
  android::binder::Status getUtInterface(
      ::android::sp<::b2g::telephony::ims::IImsUt>* _aidl_return) override;
  android::binder::Status setListener(
      const ::android::sp<::b2g::telephony::ims::IImsMMTelListener>& listener)
      override;
  android::binder::Status createCallSession(
      const ::b2g::telephony::ims::ImsCallProfileParcelable& profile,
      ::android::sp<::b2g::telephony::ims::IImsCallSession>* _aidl_return)
      override;
  android::binder::Status setSmsListener(
      const ::android::sp<::b2g::telephony::ims::IImsSmsListener>& smsListener)
      override;
  android::binder::Status sendSms(int32_t token, int32_t messageRef,
                                  const ::std::string& format,
                                  const ::std::string& smsc, bool isRetry,
                                  const ::std::vector<uint8_t>& pdu) override;
  android::binder::Status acknowledgeSms(int32_t token, int32_t messageRef,
                                         int32_t result) override;
  android::binder::Status acknowledgeSmsReport(int32_t token,
                                               int32_t messageRef,
                                               int32_t result) override;
  android::binder::Status getSmsFormat(::std::string* _aidl_return) override;
  android::binder::Status setUiTtyMode(
      int32_t uiTtyMode,
      const ::android::sp<::b2g::telephony::ims::IImsTtyCallback>& callback)
      override;
  android::binder::Status merge(
      const ::android::sp<::b2g::telephony::ims::IImsCallSession>& host,
      const ::android::sp<::b2g::telephony::ims::IImsCallSession>& peer)
      override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub

#endif  // _BASE_IMS_MMTEL_FEATURE_H_
