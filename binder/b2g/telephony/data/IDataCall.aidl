/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.telephony.data;

import b2g.telephony.data.IDataCallEventListener;

interface IDataCall {

  /**
   * DataCall default service name.
   */
  const String SERVICE_NAME = "b2g_datacall_binder";

  /**
   * Establish the data connection.
   *
   * @param sreviceId for indicate the slot.
   *
   * @param networkType NETWORK_TYPE_*( defined in IConnectivity) for indicate the setup data type.
   *
   * The result will be notified via IConnectivityEventListener#onNetworkChanged.
   */
  void setupDataCallByType(int sreviceId, int networkType);

  /**
   * Deactivate the data connection.
   *
   * @param sreviceId for indicate the slot.
   *
   * @param networkType NETWORK_TYPE_* ( defined in IConnectivity) for indicate the deativate data type.
   *
   * The result will be notified via IConnectivityEventListener#onNetworkChanged.
   */
  void deactivateDataCallByType(int sreviceId, int networkType);

  /**
   * The current data slot id (0-base)
   * @return slot id.
   */
  int getDefaultSlotId();

  /**
   * Sets listener to listen events.
   * @param listener the listener to listen events.
   *        Please refer IDataCallEventListener for possible events.
   */
  oneway void addEventListener(IDataCallEventListener listener);

  /**
   * To remove listener.
   * @param listener listener to be removed.
   */
  oneway void removeEventListener(IDataCallEventListener listener);
}
