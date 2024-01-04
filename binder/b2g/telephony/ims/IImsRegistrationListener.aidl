/*
 * Copyright (c) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.telephony.ims;

import b2g.telephony.ims.ImsReasonInfoParcelable;

/**
 * To provide callbacks for registration/service/configuration changeds.
 */
oneway interface IImsRegistrationListener {
  /**
   * Notified when ims registered with radio tech.
   *
   * @param imsRadioTech
   *        Possible values b2g.telephony.ims.RADIO_TECH_*.
   */
  void onRegistered(int imsRadioTech);

  /**
   * IMS is registering with radio tech.
   * This is optional because b2g framework currently ignore this event.
   * @param imsRadioTech
   *        Possible values: b2g.telephony.ims.IImsRegistration.RADIO_TECH_*.
   */
  void onRegistering(int imsRadioTech);

  /**
   *  IMS is unregistered with given reason.
   * @param reasonInfo possible values: TBD
   */
  void onDeregistered(int reasonInfo, @utf8InCpp String extraMessage);

  /**
   * Notified when failed to change to imsRadioTech.
   * @param imsRadioTech The radio tech we failed to switch to.
   *                     possible values: b2g.telephony.ims.IImsRegistration.RADIO_TECH_*.
   * @param reasonInfo
   *        possible values: TBD
   */
  void onTechnologyChangeFailed(int imsRadioTech, in ImsReasonInfoParcelable reason);
}
