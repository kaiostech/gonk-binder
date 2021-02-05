/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_UT_CALLBACK_H_
#define _BASE_IMS_UT_CALLBACK_H_

#include <b2g/telephony/ims/BnImsUtCallback.h>

namespace b2g_stub {
namespace telephony {
namespace ims {

class BaseImsUtCallback : public b2g::telephony::ims::BnImsUtCallback {
 public:
  // IImsUtCallback.
  android::binder::Status onCallForwardQueried(
      int32_t id,
      const ::std::vector<::b2g::telephony::ims::ImsCallForwardInfoParcelable>&
          cfInfos) override;
  android::binder::Status onUtConfigurationUpdated(int32_t id) override;
  android::binder::Status onUtConfigurationUpdateFailed(
      int32_t id,
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& error) override;
  android::binder::Status onCallBarringQueried(
      int32_t id,
      const ::b2g::telephony::ims::ImsSsInfoParcelable& cbInfo) override;
  android::binder::Status onCallWaitingQueried(
      int32_t id,
      const ::b2g::telephony::ims::ImsSsInfoParcelable& cwInfo) override;
  android::binder::Status utConfigurationQueryFailed(
      int32_t id,
      const ::b2g::telephony::ims::ImsReasonInfoParcelable& error) override;
  android::binder::Status onClirQueried(
      int32_t id,
      const ::b2g::telephony::ims::ImsClirResponseParcelable& clirStatus)
      override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub

#endif  // _BASE_IMS_UT_CALLBACK_H_
