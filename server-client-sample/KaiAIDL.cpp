/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include "KaiAIDL.h"

#ifdef CONNECTIVITY_TEST
#  include "connectivity/ConnectivityEventTest.h"
#endif

using android::IBinder;
using android::IPCThreadState;
using android::IServiceManager;
using android::sp;
using android::binder::Status;

#ifdef CONNECTIVITY_TEST
using b2g::connectivity::IConnectivity;
#endif

int main() {
  KAIOS_DEBUG("starting KaiOS_AIDL_Test.");
  sp<IServiceManager> sm = android::defaultServiceManager();

#ifdef CONNECTIVITY_TEST
  sp<IConnectivity> sConnectivity = nullptr;
  sp<IBinder> binderConnectivity;

  binderConnectivity = sm->getService(IConnectivity::SERVICE_NAME());
  KAIOS_DEBUG("acquire binderConnectivity %s",
              (binderConnectivity != nullptr) ? "success" : "failed");

  if (binderConnectivity != nullptr) {
    sConnectivity = android::interface_cast<IConnectivity>(binderConnectivity);

    // Try get something.
    bool isAlive = false;
    sConnectivity->isAlive(&isAlive);
    KAIOS_DEBUG("Connectivity binder is %s", isAlive ? "alive" : "dead");

    // Registered listener.
    auto sConnectivityEventTest = new ConnectivityEventTest();
    Status state = sConnectivity->registerEventListener(
        android::interface_cast<b2g::connectivity::IConnectivityEventListener>(
            sConnectivityEventTest));
    KAIOS_DEBUG("registered ConnectivityEventTest %s",
                state.isOk() ? "success" : "failed");
  }
#endif

  IPCThreadState::self()->joinThreadPool();
  KAIOS_DEBUG("KaiOS_AIDL_Test exiting");
  exit(0);
}
