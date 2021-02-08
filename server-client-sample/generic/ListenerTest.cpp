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
#include <b2g/connectivity/IConnectivity.h>
using b2g::connectivity::IConnectivity;
using b2g::connectivity::NetworkInfoParcel;
// TODO: REWRITE_BY_YOURSELF_END

ListenerTest::ListenerTest() {
  android::defaultServiceManager()->addService(
      android::String16(getServiceName()), this, false,
      android::IServiceManager::DUMP_FLAG_PRIORITY_DEFAULT);
  android::sp<android::ProcessState> ps(android::ProcessState::self());
  ps->startThreadPool();
}

// TODO: REWRITE_BY_YOURSELF_START
// Write your own function below.
Status ListenerTest::onActiveNetworkChanged(
    const NetworkInfoParcel& networkInfo) {
  KAIOS_LISTENER_DEBUG("onActiveNetworkChanged event.");
  if (networkInfo.state == IConnectivity::NETWORK_STATE_CONNECTED) {
    for (uint32_t i = 0; i < networkInfo.ips.size(); i++) {
      KAIOS_LISTENER_DEBUG("Dump ips[%d] : %s", i, networkInfo.ips[i].c_str());
    }
  } else {
    KAIOS_LISTENER_DEBUG("active network state[%d]", networkInfo.state);
  }
  KAIOS_LISTENER_DEBUG("onActiveNetworkChanged event done.");
  return Status::ok();
};

Status ListenerTest::onNetworkChanged(const NetworkInfoParcel& networkInfo) {
  KAIOS_LISTENER_DEBUG("onNetworkChanged event.");
  KAIOS_LISTENER_DEBUG("Dump type[%d] state[%d]", networkInfo.type,
                       networkInfo.state);
  KAIOS_LISTENER_DEBUG("onNetworkChanged event done.");
  return Status::ok();
};
// TODO: REWRITE_BY_YOURSELF_END
