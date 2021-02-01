/* (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.system;

import b2g.system.ISystemEventListener;

interface ISystem {

  /**
   * DataCall default service name.
   */
  const String SERVICE_NAME = "b2g_system_binder";

  /**
   * The current screen state.
   */
  boolean getScreenState();

  /**
   * Sets listener to listen events.
   * @param listener the listener to listen events.
   *        Please refer ISystemEventListener for possible events.
   */
  oneway void addEventListener(ISystemEventListener listener);

  /**
   * To remove listener.
   * @param listener listener to be removed.
   */
  oneway void removeEventListener(ISystemEventListener listener);
}
