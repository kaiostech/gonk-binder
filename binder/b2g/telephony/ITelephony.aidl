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

package b2g.telephony;

import b2g.telephony.ITelephonyEventListener;

interface ITelephony {
  const String SERVICE_NAME = "b2g_telephony_binder";

  // Network types
  const int NETWORK_TYPE_BITMASK_UNKNOWN  = 1; // 1 << 0
  const int NETWORK_TYPE_BITMASK_GPRS     = 2; // 1 << 1
  const int NETWORK_TYPE_BITMASK_EDGE     = 4; // 1 << 2
  const int NETWORK_TYPE_BITMASK_UMTS     = 8; // 1 << 3
  const int NETWORK_TYPE_BITMASK_IS95A    = 16; // 1 << 4
  const int NETWORK_TYPE_BITMASK_IS95B    = 32; // 1 << 5
  const int NETWORK_TYPE_BITMASK_1XRTT    = 64; // 1 << 6
  const int NETWORK_TYPE_BITMASK_EVDO_0   = 128; // 1 << 7
  const int NETWORK_TYPE_BITMASK_EVDO_A   = 256; // 1 << 8
  const int NETWORK_TYPE_BITMASK_HSDPA    = 512; // 1 << 9
  const int NETWORK_TYPE_BITMASK_HSUPA    = 1024; // 1 << 10
  const int NETWORK_TYPE_BITMASK_HSPA     = 2048; // 1 << 11
  const int NETWORK_TYPE_BITMASK_EVDO_B   = 4096; // 1 << 12
  const int NETWORK_TYPE_BITMASK_EHRPD    = 4096; // 1 << 13
  const int NETWORK_TYPE_BITMASK_LTE      = 16384; // 1 << 14
  const int NETWORK_TYPE_BITMASK_HSPAP    = 32768; // 1 << 15
  const int NETWORK_TYPE_BITMASK_GSM      = 65536; // 1 << 16
  const int NETWORK_TYPE_BITMASK_TD_SCDMA = 131072; // 1 << 17
  const int NETWORK_TYPE_BITMASK_IWLAN    = 262144; // 1 << 18
  const int NETWORK_TYPE_BITMASK_LTE_CA   = 524288; // 1 << 19
  const int NETWORK_TYPE_BITMASK_NR       = 1048576; // 1 << 20

  /**
   * Returns the supported radio access family of give slot id.
   * @param slotId the slot id you queried.
   * @return modem supported radio access family bitmask
   *         bitmap of NETWORK_TYPE_BITMASK_*.
   */
  int getSupportedRadioAccessFamily(int slotId);

  /**
   * Returns the number phone phones available.
   * @return the number phone phones.
   */
  int getPhoneCount();

  /**
   * Available radio technologies for GSM, UMTS and CDMA.
   */
  /** Network type is unknown */
  const int NETWORK_TYPE_UNKNOWN = 0;
  /** Current network is GPRS */
  const int NETWORK_TYPE_GPRS = 1;
  /** Current network is EDGE */
  const int NETWORK_TYPE_EDGE = 2;
  /** Current network is UMTS */
  const int NETWORK_TYPE_UMTS = 3;
  /** Current network is CDMA: Either IS95A or IS95B*/
  const int NETWORK_TYPE_IS95A = 4;
  const int NETWORK_TYPE_IS95B = 5;
  /** Current network is 1xRTT*/
  const int NETWORK_TYPE_1xRTT = 6;
  /** Current network is EVDO revision 0*/
  const int NETWORK_TYPE_EVDO_0 = 7;
  /** Current network is EVDO revision A*/
  const int NETWORK_TYPE_EVDO_A = 8;

  /** Current network is HSDPA */
  const int NETWORK_TYPE_HSDPA = 9;
  /** Current network is HSUPA */
  const int NETWORK_TYPE_HSUPA = 10;
  /** Current network is HSPA */
  const int NETWORK_TYPE_HSPA = 11;
  /** Current network is EVDO revision B*/
  const int NETWORK_TYPE_EVDO_B = 12;
  /** Current network is eHRPD */
  const int NETWORK_TYPE_EHRPD = 13;
  /** Current network is LTE */
  const int NETWORK_TYPE_LTE = 14;
  /** Current network is HSPA+ */
  const int NETWORK_TYPE_HSPAP = 15;
  /** Current network is GSM */
  const int NETWORK_TYPE_GSM = 16;
  /** Current network is TD_SCDMA */
  const int NETWORK_TYPE_TD_SCDMA = 17;
  /** Current network is IWLAN */
  const int NETWORK_TYPE_IWLAN = 18;
  /** Current network is LTE_CA */
  const int NETWORK_TYPE_LTE_CA = 19;
  /** Current network is NR(New Radio) 5G. */
  const int NETWORK_TYPE_NR = 20;

  /** Max network type number. Update as new types are added. Don't add negative types. {@hide} */
  const int MAX_NETWORK_TYPE = 21;

  /**
   * Indicates the available voice radio technology,
   * valid values as defined by RadioTechnology.
   * @return voice radio technology NETWORK_TYPE_*.
   */
  int getVoiceNetworkType(int slotId);

  /**
   * Indicates the available data radio technology,
   * valid values as defined by RadioTechnology.
   * @return data radio technology NETWORK_TYPE_*.
   */
  int getDataNetworkType(int slotId);

  /**
   * Sets listener to listen events.
   * @param listener the listener to listen events.
   *        Please refer ITelephonyEventListener for possible events.
   */
  oneway void addEventListener(ITelephonyEventListener listener);

  /**
   * To remove listener.
   * @param listener listener to be removed.
   */
  oneway void removeEventListener(ITelephonyEventListener listener);
}
