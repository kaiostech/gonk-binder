/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include "ListenerTest.h"
#include <b2g/connectivity/IConnectivity.h>
#include <binder/IServiceManager.h>

#define KAIOS_LISTENER_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_Listener", ##args)

using android::IBinder;
using android::IServiceManager;
using android::sp;
using android::binder::Status;

// TODO: REWRITE_BY_YOURSELF_START
#include <b2g/connectivity/IConnectivity.h>
#ifdef CLASSIC_TEST
#  include "classic/ServerTest.h"
#endif

#ifdef INHERIT_TEST
#  include "inherit/InheritServerTest.h"
#endif
using b2g::connectivity::IConnectivity;
using b2g::connectivity::NetworkInfoParcel;
// TODO: REWRITE_BY_YOURSELF_END

ListenerTest::ListenerTest() {
  android::defaultServiceManager()->addService(
      android::String16(ListenerTest::getServiceName()), this, false,
      android::IServiceManager::DUMP_FLAG_PRIORITY_DEFAULT);
  android::sp<android::ProcessState> ps(android::ProcessState::self());
  ps->startThreadPool();
}

// TODO: REWRITE_BY_YOURSELF_STAR
Status ListenerTest::onActiveNetworkChanged(
    const NetworkInfoParcel& networkInfo) {
  KAIOS_LISTENER_DEBUG("onActiveNetworkChanged event.");
  for (uint32_t i = 0; i < networkInfo.gateways.size(); i++) {
    KAIOS_LISTENER_DEBUG("Dump gateway[%d] : %s", i,
                         networkInfo.gateways[i].c_str());
  }
  KAIOS_LISTENER_DEBUG("onActiveNetworkChanged event done.");
  return Status::ok();
};

Status ListenerTest::onNetworkChanged(const NetworkInfoParcel& networkInfo) {
  KAIOS_LISTENER_DEBUG("onNetworkChanged event.");

  // Let's try get active networkinfo directly in event.
  sp<IServiceManager> sm = android::defaultServiceManager();
  sp<IConnectivity> sConnectivity = nullptr;
  sp<IBinder> binderConnectivity;
#ifdef REAL_SERVER_TEST
  // Try to reach the real binder server on device.
  binderConnectivity = sm->getService(IConnectivity::SERVICE_NAME());
#elif CLASSIC_TEST
  // Acquire test server.
  binderConnectivity =
      sm->getService(android::String16(ServerTest::getServiceName()));
#elif INHERIT_TEST
  // Acquire test inherit server.
  binderConnectivity =
      sm->getService(android::String16(InheritServerTest::getServiceName()));
#endif

  if (binderConnectivity != nullptr) {
    sConnectivity = android::interface_cast<IConnectivity>(binderConnectivity);
    NetworkInfoParcel activeNetworkInfo;
    Status activeNetworkInfoState =
        sConnectivity->getActiveNetworkInfo(&activeNetworkInfo);
    if (activeNetworkInfoState.isOk()) {
      KAIOS_LISTENER_DEBUG(
          "Current active networkinfo name:%s netId:%d type:%d state:%d",
          activeNetworkInfo.name.c_str(), activeNetworkInfo.netId,
          activeNetworkInfo.type, activeNetworkInfo.state);
    } else {
      KAIOS_LISTENER_DEBUG("Failed to get active networkinfo.");
    }

    // Get all network info.
    std::vector<NetworkInfoParcel> networkInfos;
    Status networkInfoStatus = sConnectivity->getNetworkInfos(&networkInfos);
    if (networkInfoStatus.isOk()) {
      KAIOS_LISTENER_DEBUG("Dump all networkinfos");
      for (uint32_t i = 0; i < networkInfos.size(); i++) {
        KAIOS_LISTENER_DEBUG(
            "NetworkInfo name: %s, netId: %d type: %d: state: %d",
            networkInfos[i].name.c_str(), networkInfos[i].netId,
            networkInfos[i].type, networkInfos[i].state);
      }
    } else {
      KAIOS_LISTENER_DEBUG("Failed to get networkinfo list");
    }
  }
  return Status::ok();
};
// TODO: REWRITE_BY_YOURSELF_END
