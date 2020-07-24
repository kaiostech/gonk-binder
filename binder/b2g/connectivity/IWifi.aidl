/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.connectivity;
import b2g.connectivity.IWifiStateListener;

interface IWifi {
  /**
   * Wifi state
   */
  const int WIFI_STATE_ENABLING = 1;
  const int WIFI_STATE_ENABLED = 2;
  const int WIFI_STATE_DISABLING = 3;
  const int WIFI_STATE_DISABLED = 4;

  /**
   * To get current wifi state.
   *
   * @return wifi status, possible values: WIFI_STATE_*.
   */
  int getWifiState();

  /**
   * Register wifi state listener
   *
   * @param listener of Wifi state.
   */
  void addWifiStateListener(IWifiStateListener listener);

  /**
   * Unregister wifi state listener
   *
   * @param listener of Wifi state.
   */
  void removeWifiStateListener(IWifiStateListener listener);

  /**
   * Wifi default service name.
   */
  const String SERVICE_NAME = "b2g_connectivity_wifi_binder";

}
