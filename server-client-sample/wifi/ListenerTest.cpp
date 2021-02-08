/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include "ListenerTest.h"
#include <binder/IServiceManager.h>

#define KAIOS_LISTENER_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_Listener", ##args)

using android::IBinder;
using android::IServiceManager;
using android::sp;
using android::binder::Status;

// TODO: REWRITE_BY_YOURSELF_START
#include <b2g/connectivity/IWifi.h>
using b2g::connectivity::IWifi;
// TODO: REWRITE_BY_YOURSELF_END

ListenerTest::ListenerTest() {
  android::defaultServiceManager()->addService(
      android::String16(getServiceName()), this, false,
      android::IServiceManager::DUMP_FLAG_PRIORITY_DEFAULT);
  android::sp<android::ProcessState> ps(android::ProcessState::self());
  ps->startThreadPool();
}

// TODO: REWRITE_BY_YOURSELF_STAR
// Write your own function below.
Status ListenerTest::onWifiStateChanged(int32_t state) {
  KAIOS_LISTENER_DEBUG("onWifiStateChanged event, state is %d.", state);
  return Status::ok();
};
// TODO: REWRITE_BY_YOURSELF_END
