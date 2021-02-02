/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_CONNECTIVITY_EVENT_LISTENER_H_
#define _BASE_CONNECTIVITY_EVENT_LISTENER_H_

#include <b2g/connectivity/BnConnectivityEventListener.h>

namespace kaios_binder {
namespace connectivity {

class BaseConnectivityEventListener
    : public b2g::connectivity::BnConnectivityEventListener {
 public:
  android::binder::Status onActiveNetworkChanged(
      const b2g::connectivity::NetworkInfoParcel& networkInfo) override;
  android::binder::Status onNetworkChanged(
      const b2g::connectivity::NetworkInfoParcel& networkInfo) override;
};

}  // namespace connectivity
}  // namespace kaios_binder

#endif  // _BASE_CONNECTIVITY_EVENT_LISTENER_H_
