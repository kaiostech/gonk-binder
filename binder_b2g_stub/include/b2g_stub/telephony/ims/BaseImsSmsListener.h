/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_IMS_SMS_LISTENER_H_
#define _BASE_IMS_SMS_LISTENER_H_

#include <b2g/telephony/ims/BnImsSmsListener.h>

namespace b2g_stub {
namespace telephony {
namespace ims {

class BaseImsSmsListener : public b2g::telephony::ims::BnImsSmsListener {
 public:
  // IImsSmsListener.
  android::binder::Status onSendSmsResult(int32_t token, int32_t messageRef,
                                          int32_t status, int32_t reason,
                                          int32_t networkErrorCode) override;
  android::binder::Status onSmsStatusReportReceived(
      int32_t token, const ::std::string& format,
      const ::std::vector<uint8_t>& pdu) override;
  android::binder::Status onSmsReceived(
      int32_t token, const ::std::string& format,
      const ::std::vector<uint8_t>& pdu) override;
};

}  // namespace ims
}  // namespace telephony
}  // namespace b2g_stub

#endif  // _BASE_IMS_SMS_LISTENER_H_
