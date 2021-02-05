/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_SYSTEM_H_
#define _BASE_SYSTEM_H_

#include <b2g/system/BnSystem.h>

namespace b2g_stub {
namespace system {

class BaseSystem : public b2g::system::BnSystem {
 public:
  // ISystem.
  android::binder::Status getScreenState(bool* _aidl_return) override;
  android::binder::Status addEventListener(
      const ::android::sp<::b2g::system::ISystemEventListener>& listener)
      override;
  android::binder::Status removeEventListener(
      const ::android::sp<::b2g::system::ISystemEventListener>& listener)
      override;
};

}  // namespace system
}  // namespace b2g_stub

#endif  // _BASE_SYSTEM_H_
