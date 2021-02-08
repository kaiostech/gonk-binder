/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Main.h"
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#define KAIOS_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_MAIN", ##args)

using android::IBinder;
using android::IPCThreadState;
using android::IServiceManager;
using android::sp;
using android::binder::Status;

#if defined(CLASSIC_TEST) || defined(INHERIT_TEST) || defined(REAL_SERVER_TEST)

// TODO: REWRITE_BY_YOURSELF_START
#  ifdef CLASSIC_TEST
#    include "generic/classic/ServerTest.h"
#  elif INHERIT_TEST
#    include "generic/inherit/InheritServerTest.h"
#  endif
#  include <b2g/connectivity/IConnectivity.h>
#  include "generic/ListenerTest.h"
using b2g::connectivity::IConnectivity;
using b2g::connectivity::NetworkInfoParcel;
using TestClass = b2g::connectivity::IConnectivity;

// Helper function.
void convertNetworkInfoParcel(NetworkInfoParcel& aNetworkInfo,
                              int aNetworkType) {
  if (aNetworkType == IConnectivity::NETWORK_TYPE_WIFI) {
    aNetworkInfo.name = std::string("wlan0");
    aNetworkInfo.state = IConnectivity::NETWORK_STATE_CONNECTED;
    aNetworkInfo.type = IConnectivity::NETWORK_TYPE_WIFI;
    aNetworkInfo.netId = 100;
    aNetworkInfo.prefixLengths.clear();
    aNetworkInfo.prefixLengths.push_back(24);
    aNetworkInfo.prefixLengths.push_back(64);
    aNetworkInfo.ips.clear();
    aNetworkInfo.ips.push_back(std::string("192.168.1.10"));
    aNetworkInfo.ips.push_back(std::string("fe80::1111:2222"));
    aNetworkInfo.gateways.clear();
    aNetworkInfo.gateways.push_back(std::string("192.168.1.1"));
    aNetworkInfo.gateways.push_back(std::string("fe80::2222::1111"));
    aNetworkInfo.dnses.clear();
    aNetworkInfo.dnses.push_back(std::string("168.95.1.1"));
    aNetworkInfo.dnses.push_back(std::string("2001:4860:4860::8888"));
  } else if (aNetworkType == IConnectivity::NETWORK_TYPE_MOBILE) {
    aNetworkInfo.name = std::string("rmnet_data0");
    aNetworkInfo.state = IConnectivity::NETWORK_STATE_CONNECTED;
    aNetworkInfo.type = IConnectivity::NETWORK_TYPE_MOBILE;
    aNetworkInfo.netId = 101;
    aNetworkInfo.prefixLengths.clear();
    aNetworkInfo.prefixLengths.push_back(24);
    aNetworkInfo.prefixLengths.push_back(64);
    aNetworkInfo.ips.clear();
    aNetworkInfo.ips.push_back(std::string("172.20.1.100"));
    aNetworkInfo.ips.push_back(std::string("fe80::3333:4444"));
    aNetworkInfo.gateways.clear();
    aNetworkInfo.gateways.push_back(std::string("172.20.1.1"));
    aNetworkInfo.gateways.push_back(std::string("fe80::4444::3333"));
    aNetworkInfo.dnses.clear();
    aNetworkInfo.dnses.push_back(std::string("168.95.1.1"));
    aNetworkInfo.dnses.push_back(std::string("2001:4860:4860::8888"));
  }
}
// TODO: REWRITE_BY_YOURSELF_END

void sigHandler(int aSignal);
void msleep(unsigned int aMs);
#endif

void print_usage(char* argv[]) {
  printf("Usage : %s <server/client>\n", argv[0]);
}

int main(int argc, char* argv[]) {
  if (argc < 2 ||
      !(!strncmp(argv[1], "server", 6) || !strncmp(argv[1], "client", 6))) {
    print_usage(argv);
    return 0;
  }

  KAIOS_DEBUG("starting KaiOS_AIDL_Test.");
  sp<IServiceManager> sm = android::defaultServiceManager();

  // Client mode
  if (!strncmp(argv[1], "client", 6)) {
    sp<TestClass> sInstance = nullptr;
    sp<IBinder> binder;

#ifdef REAL_SERVER_TEST
    // Try to reach real binder server on device.
    binder = sm->getService(TestClass::SERVICE_NAME());
#elif CLASSIC_TEST
    // Acquire classic test server.
    binder = sm->getService(android::String16(ServerTest::getServiceName()));
#elif INHERIT_TEST
    // Acquire inherit test server.
    binder =
        sm->getService(android::String16(InheritServerTest::getServiceName()));
#endif
    KAIOS_DEBUG("acquire binder %s",
                (binder != nullptr) ? "success" : "failed");

    if (binder != nullptr) {
      sInstance = android::interface_cast<TestClass>(binder);

      // TODO: REWRITE_BY_YOURSELF_START
      // Write your own client test process here.
      int32_t version = sInstance->getInterfaceVersion();
      KAIOS_DEBUG("binder service version is %d", version);

      // Interface version "1" start from 10000.
      if (version >= 10000) {
        // Try get something.
        bool isAlive = false;
        sInstance->isAlive(&isAlive);
        KAIOS_DEBUG("binder is %s", isAlive ? "alive" : "dead");

        // Registered listener.
        auto sListenerTest = new ListenerTest();
        Status state = sInstance->addEventListener(
            android::interface_cast<
                b2g::connectivity::IConnectivityEventListener>(sListenerTest));
        KAIOS_DEBUG("registered ListenerTest %s",
                    state.isOk() ? "success" : "failed");

        // Test functions, failed in inherit class.
        NetworkInfoParcel parcel;
        state = sInstance->getActiveNetworkInfo(&parcel);
        KAIOS_DEBUG("Try function %s", state.isOk() ? "success" : "failed");
        // TODO: REWRITE_BY_YOURSELF_END
      }
    }

    IPCThreadState::self()->joinThreadPool();
    KAIOS_DEBUG("KaiOS_AIDL_Test client exiting");

    // Server mode
  } else if (!strncmp(argv[1], "server", 6)) {
#ifdef CLASSIC_TEST
    auto sServer = new ServerTest();
#elif INHERIT_TEST
    auto sServer = new InheritServerTest();
#endif

#if defined(CLASSIC_TEST) || defined(INHERIT_TEST)
    signal(SIGINT, sigHandler);
    signal(SIGTERM, sigHandler);
    signal(SIGHUP, sigHandler);

    // TODO: REWRITE_BY_YOURSELF_START
    // Simulate update event every 10 seconds.
    NetworkInfoParcel parcel;
    int type = IConnectivity::NETWORK_TYPE_WIFI;
    // TODO: REWRITE_BY_YOURSELF_END

    for (;;) {
      msleep(10000);

      // TODO: REWRITE_BY_YOURSELF_START
      // Write your own server test process here.
      // update parcel to simulate server state change.
      type = (type == IConnectivity::NETWORK_TYPE_MOBILE)
                 ? IConnectivity::NETWORK_TYPE_WIFI
                 : IConnectivity::NETWORK_TYPE_MOBILE;
      convertNetworkInfoParcel(parcel, type);
      KAIOS_DEBUG("Update parcel type to %d", type);
      sServer->updateActiveNetworkInfo(parcel);
      sServer->updateNetworkInfo(parcel);
      // TODO: REWRITE_BY_YOURSELF_END
      if (serverStop) {
        break;
      }
    }
#else
    KAIOS_DEBUG(
        "Server mode is not support since REAL_SERVER_TEST flag is "
        "raise.");
#endif
  }
  exit(0);
}

#if defined(CLASSIC_TEST) || defined(INHERIT_TEST)
void sigHandler(int aSignal) {
  switch (aSignal) {
    case SIGTERM:
    case SIGHUP:
    case SIGINT:
      serverStop = 1;
      break;
  }
}

void msleep(unsigned int ms) {
  int microsecs;
  struct timeval tv;
  microsecs = ms * 1000;
  tv.tv_sec = microsecs / 1000000;
  tv.tv_usec = microsecs % 1000000;
  select(0, NULL, NULL, NULL, &tv);
}
#endif
