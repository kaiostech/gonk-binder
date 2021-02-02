/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <kaios_binder/telephony/ims/BaseImsUt.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::ims::IImsUtCallback;

namespace kaios_binder {
namespace telephony {
namespace ims {

// IImsUt.
Status BaseImsUt::setCallback(const sp<IImsUtCallback>& callback) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUt::queryCallForward(int32_t condition,
                                   const ::std::string& number,
                                   int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUt::updateCallForward(int32_t action, int32_t condition,
                                    const ::std::string& number,
                                    int32_t serviceClass, int32_t timeSeconds,
                                    int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUt::queryCallBarring(int32_t cbType, int32_t serviceClass,
                                   int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUt::updateCallBarring(
    int32_t cbType, int32_t action,
    const ::std::vector<::std::string>& barrList, int32_t serviceClass,
    const ::std::string& password, int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUt::queryCallWaiting(int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUt::updateCallWaiting(bool enable, int32_t serviceClass,
                                    int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUt::queryCLIR(int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsUt::updateCLIR(int32_t clirMode, int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder
