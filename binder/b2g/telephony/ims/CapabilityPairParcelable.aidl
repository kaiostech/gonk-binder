/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.telephony.ims;

parcelable CapabilityPairParcelable {
  /**
  * The capabilieis.
  * Possible values are b2g.telephony.ims.IImsMMTelService.CAPABILITY_*.
  */
  int capability;

  /**
  * The radio techonoligies.
  * Possible values b2g.telephony.ims.IImsRegistration.RADIO_TECH_*.
  */
  int radioTech;
}