/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _BASE_CONNECTIVITY_H_
#define _BASE_CONNECTIVITY_H_

#include <b2g/connectivity/BnConnectivity.h>

namespace kaios_binder {
namespace connectivity {

class BaseConnectivity : public b2g::connectivity::BnConnectivity {
 public:
  android::binder::Status isAlive(bool* _aidl_return) override;

  // Network function.
  android::binder::Status addEventListener(
      const android::sp<b2g::connectivity::IConnectivityEventListener>&
          listener) override;

  android::binder::Status removeEventListener(
      const android::sp<b2g::connectivity::IConnectivityEventListener>&
          listener) override;

  android::binder::Status getActiveNetworkInfo(
      b2g::connectivity::NetworkInfoParcel* _aidl_return) override;

  android::binder::Status getNetworkInfos(
      std::vector<b2g::connectivity::NetworkInfoParcel>* _aidl_return) override;

  // Tethering function.
  android::binder::Status getTetheringStatus(
      b2g::connectivity::TetheringStatusParcel* _aidl_return) override;

  android::binder::Status addTetheringStatusListener(
      const android::sp<b2g::connectivity::ITetheringStatusListener>& listener)
      override;

  android::binder::Status removeTetheringStatusListener(
      const android::sp<b2g::connectivity::ITetheringStatusListener>& listener)
      override;

  // Captive portal function.
  android::binder::Status getCaptivePortalLandings(
      std::vector<b2g::connectivity::CaptivePortalLandingParcel>* _aidl_return)
      override;

  android::binder::Status addCaptivePortalLandingListener(
      const android::sp<b2g::connectivity::ICaptivePortalLandingListener>&
          listener) override;

  android::binder::Status removeCaptivePortalLandingListener(
      const android::sp<b2g::connectivity::ICaptivePortalLandingListener>&
          listener) override;
};

}  // namespace connectivity
}  // namespace kaios_binder

#endif  // _BASE_CONNECTIVITY_H_
