/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <b2g_stub/telephony/ims/BaseImsServiceManager.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::IDeathNotifier;
using b2g::telephony::ims::IImsConfig;
using b2g::telephony::ims::IImsEcbm;
using b2g::telephony::ims::IImsFeatureStatusListener;
using b2g::telephony::ims::IImsMMTelFeature;
using b2g::telephony::ims::IImsRegistration;

namespace b2g_stub {
namespace telephony {
namespace ims {

// IImsServiceManager.
Status BaseImsServiceManager::turnOnIms(int32_t slotId, bool on) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsServiceManager::getRegistration(
    int32_t slotId, sp<IImsRegistration>* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsServiceManager::getConfig(int32_t slotId,
                                        sp<IImsConfig>* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsServiceManager::createMmTelFeature(
    int32_t slotId, const sp<IImsFeatureStatusListener>& listener,
    sp<IImsMMTelFeature>* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsServiceManager::setDeathNotifier(
    const sp<IDeathNotifier>& aNotifier) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsServiceManager::getEcbm(int32_t slotId,
                                      sp<IImsEcbm>* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub
