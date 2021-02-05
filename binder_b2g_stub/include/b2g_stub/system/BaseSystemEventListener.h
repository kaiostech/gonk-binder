/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_SYSTEM_EVENT_LISTENER_H_
#define _BASE_SYSTEM_EVENT_LISTENER_H_

#include <b2g/system/BnSystemEventListener.h>

namespace b2g_stub {
namespace system {

class BaseSystemEventListener : public b2g::system::BnSystemEventListener {
 public:
  android::binder::Status onScreenStateChanged() override;
};

}  // namespace system
}  // namespace b2g_stub

#endif  // _BASE_SYSTEM_EVENT_LISTENER_H_
