/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <kaios_binder/telephony/ims/BaseImsDtmfCallback.h>

using android::binder::Status;

namespace kaios_binder {
namespace telephony {
namespace ims {

// IImsDtmfCallback.
Status BaseImsDtmfCallback::onDtmfDone() {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace ims
}  // namespace telephony
}  // namespace kaios_binder
