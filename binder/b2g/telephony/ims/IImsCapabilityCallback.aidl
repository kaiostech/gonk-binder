/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */


package b2g.telephony.ims;

oneway interface IImsCapabilityCallback {
  /**
   * To notify caller the result of IImsMMTelFeature.changeCapability().
   * @param capability
   *        Possible values: b2g.telephony.ims.IImsMMTelFeature.CAPABILITY_TYPE_*.
   * @param radioTech
   *        Possible values: b2g.telephony.ims.IImsRegistration.RADIO_TECH_*.
   * @param status
   *        Possible values: b2g.telephony.ims.IImsConfig.OPERATION_STATUS_*.
   */
  void onChangeCapabilityResponse(int capability, int radioTech, int status);
}