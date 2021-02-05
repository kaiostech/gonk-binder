/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_SERVICEMANAGER_H_
#define _BASE_IMS_SERVICEMANAGER_H_

#include <b2g/telephony/ims/BnImsServiceManager.h>

namespace b2g_stub {
namespace telephony {
namespace ims {

class BaseImsServiceManager : public b2g::telephony::ims::BnImsServiceManager {
 public:
  // IImsServiceManager.
  android::binder::Status turnOnIms(int32_t slotId, bool on) override;
  android::binder::Status getRegistration(
      int32_t slotId,
      ::android::sp<::b2g::telephony::ims::IImsRegistration>* _aidl_return)
      override;
  android::binder::Status getConfig(
      int32_t slotId,
      ::android::sp<::b2g::telephony::ims::IImsConfig>* _aidl_return) override;
  android::binder::Status createMmTelFeature(
      int32_t slotId,
      const ::android::sp<::b2g::telephony::ims::IImsFeatureStatusListener>&
          listener,
      ::android::sp<::b2g::telephony::ims::IImsMMTelFeature>* _aidl_return)
      override;
  android::binder::Status setDeathNotifier(
      const ::android::sp<::b2g::telephony::IDeathNotifier>& aNotifier)
      override;
  android::binder::Status getEcbm(
      int32_t slotId,
      ::android::sp<::b2g::telephony::ims::IImsEcbm>* _aidl_return) override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub

#endif  // _BASE_IMS_SERVICEMANAGER_H_
