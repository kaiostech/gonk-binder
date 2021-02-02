/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_DATACALL_EVENT_LISTENER_H_
#define _BASE_DATACALL_EVENT_LISTENER_H_

#include <b2g/telephony/data/BnDataCallEventListener.h>

namespace kaios_binder {
namespace telephony {
namespace data {

class BaseDataCallEventListener
    : public b2g::telephony::data::BnDataCallEventListener {
 public:
  // IDataCallEventListener.
  android::binder::Status onDefaultSlotIdChanged(int32_t slotId) override;
};

}  // namespace data
}  // namespace telephony
}  // namespace kaios_binder

#endif  // _BASE_DATACALL_EVENT_LISTENER_H_