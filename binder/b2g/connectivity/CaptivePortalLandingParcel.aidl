/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.connectivity;

/**
 * Captive portal landing information.
 *
 */
parcelable CaptivePortalLandingParcel {
  /**
   * Network type of captive portal, one of the b2g.connectivity.IConnectivity.NETWORK_TYPE_* constants.
   *
   */
  int networkType;

  /**
   * Captive portal landing status.
   *
   */
  boolean landing;
}
