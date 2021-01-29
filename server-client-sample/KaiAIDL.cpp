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

#include "KaiAIDL.h"
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#ifdef CONNECTIVITY_CLASSIC_TEST
#  include "connectivity/classic/ConnectivityServerTest.h"
#endif
#ifdef CONNECTIVITY_INHERIT_TEST
#  include "connectivity/inherit/ConnectivityInheritServer.h"
#endif

#if defined(CONNECTIVITY_CLASSIC_TEST) || \
    defined(CONNECTIVITY_INHERIT_TEST) || defined(CONNECTIVITY_REAL_SERVER)
#  include "connectivity/CaptivePortalListenerTest.h"
#  include "connectivity/ConnectivityListenerTest.h"
#  include "connectivity/TetheringListenerTest.h"
#endif

#define KAIOS_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_MAIN", ##args)

using android::IBinder;
using android::IPCThreadState;
using android::IServiceManager;
using android::sp;
using android::binder::Status;

#if defined(CONNECTIVITY_CLASSIC_TEST) || \
    defined(CONNECTIVITY_INHERIT_TEST) || defined(CONNECTIVITY_REAL_SERVER)
using b2g::connectivity::CaptivePortalLandingParcel;
using b2g::connectivity::IConnectivity;
using b2g::connectivity::NetworkInfoParcel;
using b2g::connectivity::TetheringStatusParcel;
void sigHandler(int aSignal);
void msleep(unsigned int aMs);
void convertNetworkInfoParcel(NetworkInfoParcel& aNetworkInfo,
                              int aNetworkType);
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
    sp<IConnectivity> sConnectivity = nullptr;
    sp<IBinder> binderConnectivity;

#ifdef CONNECTIVITY_REAL_SERVER
    // Try to reach real binder server on device.
    binderConnectivity = sm->getService(IConnectivity::SERVICE_NAME());
#endif
#ifdef CONNECTIVITY_CLASSIC_TEST
    // Acquire classic test server.
    binderConnectivity = sm->getService(
        android::String16(ConnectivityServerTest::getServiceName()));
#endif
#ifdef CONNECTIVITY_INHERIT_TEST
    // Acquire inherit test server.
    binderConnectivity = sm->getService(
        android::String16(ConnectivityInheritServer::getServiceName()));
#endif
    KAIOS_DEBUG("acquire binderConnectivity %s",
                (binderConnectivity != nullptr) ? "success" : "failed");

    if (binderConnectivity != nullptr) {
      sConnectivity =
          android::interface_cast<IConnectivity>(binderConnectivity);

      int32_t version = sConnectivity->getInterfaceVersion();
      KAIOS_DEBUG("Connectivity binder service version is %d", version);

      // Interface version "1" start from 10000.
      if (version >= 10000) {
        // Try get something.
        bool isAlive = false;
        sConnectivity->isAlive(&isAlive);
        KAIOS_DEBUG("Connectivity binder is %s", isAlive ? "alive" : "dead");

        // Registered listener.
        auto sConnectivityListenerTest = new ConnectivityListenerTest();
        Status state = sConnectivity->addEventListener(
            android::interface_cast<
                b2g::connectivity::IConnectivityEventListener>(
                sConnectivityListenerTest));
        KAIOS_DEBUG("registered ConnectivityListenerTest %s",
                    state.isOk() ? "success" : "failed");

        // Registered tethering listener.
        auto sTetheringListenerTest = new TetheringListenerTest();
        Status tetheringState = sConnectivity->addTetheringStatusListener(
            android::interface_cast<
                b2g::connectivity::ITetheringStatusListener>(
                sTetheringListenerTest));
        KAIOS_DEBUG("registered TetheringListenerTest %s",
                    tetheringState.isOk() ? "success" : "failed");

        // Registered captive portal listener.
        auto sCaptivePortalListenerTest = new CaptivePortalListenerTest();
        Status captivePortal = sConnectivity->addCaptivePortalLandingListener(
            android::interface_cast<
                b2g::connectivity::ICaptivePortalLandingListener>(
                sCaptivePortalListenerTest));
        KAIOS_DEBUG("registered CaptivePortalListenerTest %s",
                    captivePortal.isOk() ? "success" : "failed");
      }
    }

    IPCThreadState::self()->joinThreadPool();
    KAIOS_DEBUG("KaiOS_AIDL_Test client exiting");

    // Server mode
  } else if (!strncmp(argv[1], "server", 6)) {
#ifdef CONNECTIVITY_CLASSIC_TEST
    auto sConnectivityServer = new ConnectivityServerTest();
#endif
#ifdef CONNECTIVITY_INHERIT_TEST
    auto sConnectivityServer = new ConnectivityInheritServer();
#endif

#if defined(CONNECTIVITY_CLASSIC_TEST) || defined(CONNECTIVITY_INHERIT_TEST)
    signal(SIGINT, sigHandler);
    signal(SIGTERM, sigHandler);
    signal(SIGHUP, sigHandler);

    NetworkInfoParcel networkInfoParcel;
    TetheringStatusParcel tetheringStatusParcel;
    CaptivePortalLandingParcel captivePortalParcel;
    int networkType = IConnectivity::NETWORK_TYPE_WIFI;
    captivePortalParcel.networkType = networkType;

    // Simulate update event every 10 seconds.
    for (;;) {
      msleep(10000);
      // Network info update.
      networkType = (networkType == IConnectivity::NETWORK_TYPE_MOBILE)
                        ? IConnectivity::NETWORK_TYPE_WIFI
                        : IConnectivity::NETWORK_TYPE_MOBILE;
      convertNetworkInfoParcel(networkInfoParcel, networkType);
      KAIOS_DEBUG("Update networkInfo to %d", networkType);
      sConnectivityServer->updateActiveNetworkInfo(networkInfoParcel);
      sConnectivityServer->updateNetworkInfo(networkInfoParcel);

      // Test inherit case without implement full IConnectivity functions.
#  ifdef CONNECTIVITY_CLASSIC_TEST
      // Tethering status update.
      tetheringStatusParcel.wifiState =
          (tetheringStatusParcel.wifiState ==
           IConnectivity::TETHERING_STATE_INACTIVE)
              ? IConnectivity::TETHERING_STATE_ACTIVE
              : IConnectivity::TETHERING_STATE_INACTIVE;
      KAIOS_DEBUG("Update wifi tethering to %d",
                  tetheringStatusParcel.wifiState);
      sConnectivityServer->updateTetheringStatus(tetheringStatusParcel);

      // Captive portal landing update.
      captivePortalParcel.landing = captivePortalParcel.landing ? false : true;
      KAIOS_DEBUG("Update captive portal networkType %d to landing %s",
                  captivePortalParcel.networkType,
                  captivePortalParcel.landing ? "true" : "false");
      sConnectivityServer->updateCaptivePortal(captivePortalParcel);
#  endif
      if (serverStop) {
        break;
      }
    }
#else
    KAIOS_DEBUG(
        "Server mode is not support since CONNECTIVITY_REAL_SERVER flag is "
        "raise.");
#endif
  }
  exit(0);
}

#if defined(CONNECTIVITY_CLASSIC_TEST) || defined(CONNECTIVITY_INHERIT_TEST)
void sigHandler(int aSignal) {
  switch (aSignal) {
    case SIGTERM:
    case SIGHUP:
    case SIGINT:
      serverStop = 1;
      break;
  }
}

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
#endif
