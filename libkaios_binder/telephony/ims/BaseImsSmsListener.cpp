/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <kaios_binder/telephony/ims/BaseImsSmsListener.h>

using android::sp;
using android::binder::Status;

namespace kaios_binder {
namespace telephony {
namespace ims {

// IImsSmsListener.
Status BaseImsSmsListener::onSendSmsResult(int32_t token, int32_t messageRef,
                                           int32_t status, int32_t reason,
                                           int32_t networkErrorCode) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsSmsListener::onSmsStatusReportReceived(
    int32_t token, const ::std::string& format,
    const ::std::vector<uint8_t>& pdu) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseImsSmsListener::onSmsReceived(int32_t token,
                                         const ::std::string& format,
                                         const ::std::vector<uint8_t>& pdu) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder
