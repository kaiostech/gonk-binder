/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#include <b2g_stub/connectivity/BaseConnectivity.h>

using android::sp;
using android::binder::Status;
using b2g::connectivity::CaptivePortalLandingParcel;
using b2g::connectivity::ICaptivePortalLandingListener;
using b2g::connectivity::IConnectivityEventListener;
using b2g::connectivity::ITetheringStatusListener;
using b2g::connectivity::NetworkInfoParcel;
using b2g::connectivity::TetheringStatusParcel;

namespace b2g_stub {
namespace connectivity {

Status BaseConnectivity::isAlive(bool* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

// Network function
Status BaseConnectivity::addEventListener(
    const sp<IConnectivityEventListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseConnectivity::removeEventListener(
    const sp<IConnectivityEventListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseConnectivity::getActiveNetworkInfo(NetworkInfoParcel* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseConnectivity::getNetworkInfos(
    std::vector<NetworkInfoParcel>* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

// Tethering function
Status BaseConnectivity::getTetheringStatus(
    TetheringStatusParcel* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseConnectivity::addTetheringStatusListener(
    const sp<ITetheringStatusListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseConnectivity::removeTetheringStatusListener(
    const sp<ITetheringStatusListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

// Captive portal function
Status BaseConnectivity::getCaptivePortalLandings(
    std::vector<CaptivePortalLandingParcel>* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseConnectivity::addCaptivePortalLandingListener(
    const sp<ICaptivePortalLandingListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

Status BaseConnectivity::removeCaptivePortalLandingListener(
    const sp<ICaptivePortalLandingListener>& listener) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}

}  // namespace connectivity
}  // namespace b2g_stub
