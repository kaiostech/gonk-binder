/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _CAPTIVE_PORTAL_LISTENER_TEST_H_
#define _CAPTIVE_PORTAL_LISTENER_TEST_H_

#include <b2g/connectivity/BnCaptivePortalLandingListener.h>
#include <binder/BinderService.h>

class CaptivePortalListenerTest
    : public android::BinderService<CaptivePortalListenerTest>,
      public b2g::connectivity::BnCaptivePortalLandingListener {
 public:
  CaptivePortalListenerTest();
  ~CaptivePortalListenerTest() = default;

  static char const* getServiceName() { return "captivePortalListenerTest"; }
  android::binder::Status onCaptivePortalLandingChanged(
      const ::b2g::connectivity::CaptivePortalLandingParcel&
          captivePortalLandingParcel) override;
};

#endif  // _CAPTIVE_PORTAL_LISTENER_TEST_H_
