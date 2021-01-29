/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include "WifiListenerTest.h"
#include <b2g/connectivity/IWifi.h>
#include <binder/IServiceManager.h>

#define KAIOS_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_WifiListener", ##args)

using android::IBinder;
using android::IServiceManager;
using android::binder::Status;
using b2g::connectivity::IWifi;

WifiListenerTest::WifiListenerTest() {
  android::defaultServiceManager()->addService(
      android::String16(WifiListenerTest::getServiceName()), this, false,
      android::IServiceManager::DUMP_FLAG_PRIORITY_DEFAULT);
  android::sp<android::ProcessState> ps(android::ProcessState::self());
  ps->startThreadPool();
}

Status WifiListenerTest::onWifiStateChanged(int32_t state) {
  KAIOS_DEBUG("onWifiStateChanged: wifiState=%d", state);
  return Status::ok();
};
