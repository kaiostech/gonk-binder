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
 * Configuration details for a network information.
 *
 */
parcelable NetworkInfoParcel {
  /**
   * Interface name of the network interface this network info belongs to.
   */
  @utf8InCpp String name;

  /**
   * Interface netid of the network interface.
   */
  int netId;

  /**
   * Current network state, one of the b2g.connectivity.IConnectivity.NETWORK_STATE_* constants.
   *
   */
  int state;

  /**
   * Network type. One of the b2g.connectivity.IConnectivity.NETWORK_TYPE_* constants.
   */
  int type;

  /**
   * Get the list of prefix lengths of ip address.
   */
  int[] prefixLengths;

  /**
   * Get the list of ip address, ip address could be IPv4 or IPv6.
   */
  @utf8InCpp String[] ips;

  /**
   * Get the list of gateways, could be IPv4 or IPv6.
   */
  @utf8InCpp String[] gateways;

  /**
   * Get the list of dnses, could be IPv4 or IPv6.
   *
   */
  @utf8InCpp String[] dnses;
}
