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

/**
 * IMS call profile constants.
 */
interface IImsCallProfile {
  /**
   * Service types.
   */
  /**
   * It is for a special case. It helps that the application can make a call
   * without IMS connection (not registered).
   * In the moment of the call initiation, the device try to connect to the IMS network
   * and initiates the call.
   */
  const int SERVICE_TYPE_NONE = 0;

  /**
   * Default type and can be selected when device is connected to the IMS network.
   */
  const int SERVICE_TYPE_NORMAL = 1;

  /**
   * For emergency call.
   */
  const int SERVICE_TYPE_EMERGENCY = 2;

  /**
   * Call types.
   */
  /**
   * IMSPhone to support IR.92 & IR.94 (voice + video upgrade/downgrade)
   */
  const int CALL_TYPE_VOICE_N_VIDEO = 1;
  /**
   * IR.92 (Voice only)
   */
  const int CALL_TYPE_VOICE = 2;
  /**
   * VT to support IR.92 & IR.94 (voice + video upgrade/downgrade)
   */
  const int CALL_TYPE_VIDEO_N_VOICE = 3;
  /**
   * Video Telephony (audio / video two way)
   */
  const int CALL_TYPE_VT = 4;
  /**
   * Video Telephony (audio two way / video TX one way)
   */
  const int CALL_TYPE_VT_TX = 5;
  /**
   * Video Telephony (audio two way / video RX one way)
   */
  const int CALL_TYPE_VT_RX = 6;
  /**
   * Video Telephony (audio two way / video inactive)
   */
  const int CALL_TYPE_VT_NODIR = 7;
  /**
   * VideoShare (video two way)
   */
  const int CALL_TYPE_VS = 8;
  /**
   * VideoShare (video TX one way)
   */
  const int CALL_TYPE_VS_TX = 9;
  /**
   * VideoShare (video RX one way)
   */
  const int CALL_TYPE_VS_RX = 10;

  /**
   * Values for OIR / CNAP
   */
  /**
   * Default presentation for Originating Identity.
   */
  const int OIR_DEFAULT = 0;    // "user subscription default value"
  /**
   * Restricted presentation for Originating Identity.
   */
  const int OIR_PRESENTATION_RESTRICTED = 1;
  /**
   * Not restricted presentation for Originating Identity.
   */
  const int OIR_PRESENTATION_NOT_RESTRICTED = 2;
  /**
   * Presentation unknown for Originating Identity.
   */
  const int OIR_PRESENTATION_UNKNOWN = 3;
  /**
   * Payphone presentation for Originating Identity.
   */
  const int OIR_PRESENTATION_PAYPHONE = 4;

  /**
   * Values for IImsCallProfileParcelable.dialString.
   */

  /**
   * A default or normal call.
   */
  const int DIALSTRING_NORMAL = 0;
  // const int DIALSTRING_SS_CONF = 1;
  // const int DIALSTRING_USSD = 2;

  // Shake & Stir.
  /**
   * Indicates that the network could not perform verification.
   */
  const int VERIFICATION_STATUS_NOT_VERIFIED = 0;

  /**
   * Indicates that verification by the network passed.  This indicates there is a high likelihood
   * that the call originated from a valid source.
   */
  const int VERIFICATION_STATUS_PASSED = 1;

  /**
   * Indicates that verification by the network failed.  This indicates there is a high likelihood
   * that the call did not originate from a valid source.
   */
  const int VERIFICATION_STATUS_FAILED = 2;

  /**
   * Call is not restricted on peer side and High Definition media is supported
   */
  const int CALL_RESTRICT_CAUSE_NONE = 0;

  /**
   * High Definition media is not supported on the peer side due to the Radio Access Technology
   * (RAT) it is are connected to.
   */
  const int CALL_RESTRICT_CAUSE_RAT = 1;

  /**
   * The service has been disabled on the peer side.
   */
  const int CALL_RESTRICT_CAUSE_DISABLED = 2;

  /**
   * High definition media is not currently supported.
   */
  const int CALL_RESTRICT_CAUSE_HD = 3;
}