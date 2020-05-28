/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <binder/IServiceManager.h>
#include "CaptivePortalListenerTest.h"
#include <b2g/connectivity/IConnectivity.h>

#define KAIOS_CAP_DEBUG(args...)                                            \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_CaptivePortalListener", \
                      ##args)

using android::IBinder;
using android::IServiceManager;
using android::sp;
using android::binder::Status;
using b2g::connectivity::CaptivePortalLandingParcel;
using b2g::connectivity::IConnectivity;

CaptivePortalListenerTest::CaptivePortalListenerTest() {
  android::defaultServiceManager()->addService(
      android::String16(CaptivePortalListenerTest::getServiceName()), this,
      false, android::IServiceManager::DUMP_FLAG_PRIORITY_DEFAULT);
  android::sp<android::ProcessState> ps(android::ProcessState::self());
  ps->startThreadPool();
}

Status CaptivePortalListenerTest::onCaptivePortalLandingChanged(
    const CaptivePortalLandingParcel& captivePortalLandingParcel) {
  KAIOS_CAP_DEBUG("onCaptivePortalLandingChanged. : networkType %d landing %s",
                  captivePortalLandingParcel.networkType,
                  captivePortalLandingParcel.landing ? "true" : "false");
  return Status::ok();
};
