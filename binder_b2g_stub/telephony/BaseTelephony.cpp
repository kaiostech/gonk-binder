/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <b2g_stub/telephony/BaseTelephony.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ITelephonyEventListener;

namespace b2g_stub {
namespace telephony {

// ITelephony.
Status BaseTelephony::getSupportedRadioAccessFamily(int32_t slotId,
                                                    int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseTelephony::getPhoneCount(int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseTelephony::getVoiceNetworkType(int32_t slotId,
                                          int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseTelephony::getDataNetworkType(int32_t slotId,
                                         int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseTelephony::addEventListener(
    const sp<ITelephonyEventListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseTelephony::removeEventListener(
    const sp<ITelephonyEventListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace telephony
}  // namespace b2g_stub
