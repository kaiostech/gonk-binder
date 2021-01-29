/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <kaios_binder/telephony/data/BaseDataCall.h>

using android::sp;
using android::binder::Status;
using b2g::telephony::data::IDataCallEventListener;

namespace kaios_binder {
namespace telephony {
namespace data {

Status BaseDataCall::setupDataCallByType(int32_t sreviceId,
                                         int32_t networkType) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseDataCall::deactivateDataCallByType(int32_t sreviceId,
                                              int32_t networkType) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseDataCall::getDefaultSlotId(int32_t* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseDataCall::addEventListener(
    const sp<IDataCallEventListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseDataCall::removeEventListener(
    const sp<IDataCallEventListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace data
}  // namespace telephony
}  // namespace kaios_binder
