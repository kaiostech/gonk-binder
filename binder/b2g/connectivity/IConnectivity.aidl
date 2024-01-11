/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.connectivity;
import b2g.connectivity.NetworkInfoParcel;
import b2g.connectivity.IConnectivityEventListener;
import b2g.connectivity.TetheringStatusParcel;
import b2g.connectivity.ITetheringStatusListener;
import b2g.connectivity.CaptivePortalLandingParcel;
import b2g.connectivity.ICaptivePortalLandingListener;

interface IConnectivity {
  /**
   * Returns true if the service is responding.
   */
  boolean isAlive();

  /**
   * Returns current active NetworkInfo.
   */
  NetworkInfoParcel getActiveNetworkInfo();

  /**
   * Returns all NetworkInfo list.
   */
  NetworkInfoParcel[] getNetworkInfos();

  /**
   * Register connectivity event listener
   *
   * @param listener Connectivity event listener to register
   */
  void addEventListener(IConnectivityEventListener listener);

  /**
   * Unregister connectivity event listener
   *
   * @param listener Connectivity event listener to register
   */
  void removeEventListener(IConnectivityEventListener listener);

  /**
   * Returns current tethering status.
   */
  TetheringStatusParcel getTetheringStatus();

  /**
   * Register tethering status listener
   *
   * @param listener Tethering status listener to register
   */
  void addTetheringStatusListener(ITetheringStatusListener listener);

  /**
   * Unregister tethering status listener
   *
   * @param listener Tethering status listener to register
   */
  void removeTetheringStatusListener(ITetheringStatusListener listener);

  /**
   * Returns captive portal landing list.
   */
  CaptivePortalLandingParcel[] getCaptivePortalLandings();

  /**
   * Register captive portal landing listener
   *
   * @param listener Captive portal landing listener to register
   */
  void addCaptivePortalLandingListener(ICaptivePortalLandingListener listener);

  /**
   * Unregister captive portal landing listener
   *
   * @param listener Captive portal listener to register
   */
  void removeCaptivePortalLandingListener(ICaptivePortalLandingListener listener);

  /**
   * Connectivity default service name.
   */
  const String SERVICE_NAME = "b2g_connectivity_binder";

  /**
   * Network state, sync from nsINetworkInterface.idl.
   */
  const int NETWORK_STATE_UNKNOWN = -1;
  const int NETWORK_STATE_CONNECTING = 0;
  const int NETWORK_STATE_CONNECTED = 1;
  const int NETWORK_STATE_DISCONNECTING = 2;
  const int NETWORK_STATE_DISCONNECTED = 3;
  const int NETWORK_STATE_ENABLED = 4;
  const int NETWORK_STATE_DISABLED = 5;
  const int NETWORK_STATE_SUSPENDED = 6;

  /**
   * Network type, sync from nsINetworkInterface.idl.
   */
  const int NETWORK_TYPE_UNKNOWN = -1;
  const int NETWORK_TYPE_WIFI = 0;
  const int NETWORK_TYPE_MOBILE = 1;
  const int NETWORK_TYPE_MOBILE_MMS = 2;
  const int NETWORK_TYPE_MOBILE_SUPL = 3;
  const int NETWORK_TYPE_WIFI_P2P = 4;
  const int NETWORK_TYPE_MOBILE_IMS = 5;
  const int NETWORK_TYPE_MOBILE_DUN = 6;
  const int NETWORK_TYPE_MOBILE_FOTA = 7;
  const int NETWORK_TYPE_ETHERNET = 8;
  const int NETWORK_TYPE_MOBILE_HIPRI = 9;
  const int NETWORK_TYPE_MOBILE_CBS = 10;
  const int NETWORK_TYPE_MOBILE_IA = 11;
  const int NETWORK_TYPE_MOBILE_ECC = 12;
  const int NETWORK_TYPE_MOBILE_XCAP = 13;

  /**
   * Tethering state, sync from nsITetheringService.idl.
   */
  const int TETHERING_STATE_INACTIVE = 0;
  const int TETHERING_STATE_ACTIVE = 1;

}
