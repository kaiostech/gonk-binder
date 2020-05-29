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

import b2g.telephony.ims.IImsCallSessionListener;
import b2g.telephony.ims.IImsDtmfCallback;
import b2g.telephony.ims.ImsStreamMediaProfileParcelable;
import b2g.telephony.ims.ImsCallProfileParcelable;

interface IImsCallSession {
  /**
   * The call ID of the session.
   * @return call ID.
   */
  @utf8InCpp String getCallId();

  /**
   * Gets the call profile that this session is associated with.
   * @return the call profile.
   */
  ImsCallProfileParcelable getCallProfile();

  // Kai doesn't support loca/remote call profile for now.
  // ImsCallProfile getLocalCallProfile();
  // ImsCallProfile getRemoteCallProfile();

  /**
   * Call session states.
   */
  const int STATE_IDLE = 0;
  const int STATE_INITIATED = 1;
  const int STATE_NEGOTIATING = 2;
  const int STATE_ESTABLISHING = 3;
  const int STATE_ESTABLISHED = 4;

  const int STATE_RENEGOTIATING = 5;
  const int STATE_REESTABLISHING = 6;

  const int STATE_TERMINATING = 7;
  const int STATE_TERMINATED = 8;

  const int STATE_INVALID = -1;
  /**
   * Gets the session state.
   *
   * @return the session state. Possible values are STATE_*.
   */
  int getState();

  /**
   * Sets listener to listen session events of this object.
   *
   * @param listener to listen events of this call session.
   */
  oneway void setListener(in IImsCallSessionListener listener);

  /**
   * Initiates an IMS call with specified profile and callee.
   *
   * @param callee dialed string to make call to.
   * @param profile call profile to make call to with specified service call
   *      type and media information.
   */
  void start(@utf8InCpp String callee, in ImsCallProfileParcelable profile);

  /**
   * To accept an incoming call.
   *
   * @param callType call type to be answered.
   * @param profile stream media profile to be answered.
   */
  void accept(int callType, in ImsStreamMediaProfileParcelable profile);

  /**
   * To reject a incoming call or session update.
   *
   * @param reason reject reason.
   *      Possible values: IImsReasonInfo#CODE_USER_*.
   */
  void reject(int reason);

  /**
   * To terminate a call.
   *
   * @param reason termination reason.
   *      Possible values: IImsReasonInfo#CODE_USER_*.
   */
  void terminate(int reason);

  /**
   * To put a call on hold.
   */
  void hold();

  /**
   * To resume a held call.
   */
  void resume();

  /**
   * Sends a DTMF code. According to <a href="http://tools.ietf.org/html/rfc2833">RFC 2833</a>,
   * event 0 ~ 9 maps to decimal value 0 ~ 9, '*' to 10, '#' to 11, event 'A' ~ 'D' to 12 ~ 15,
   * and event flash to 16.
   *
   * @param c the DTMF to send. '0' ~ '9', 'A' ~ 'D', '*', '#' are valid inputs.
   * @param callback dtmf sending result callback.
   */
  void sendDtmf(char c, in IImsDtmfCallback callback);

  /**
   * Start a DTMF code. According to <a href="http://tools.ietf.org/html/rfc2833">RFC 2833</a>,
   * event 0 ~ 9 maps to decimal value 0 ~ 9, '*' to 10, '#' to 11, event 'A' ~ 'D' to 12 ~ 15,
   * and event flash to 16.
   *
   * @param c the DTMF to send. '0' ~ '9', 'A' ~ 'D', '*', '#' are valid inputs.
   */
  void startDtmf(char c);

  /**
   * Stop a DTMF code.
   */
  void stopDtmf();

  /**
   * To close this call session.
   * This objection is not usable after been closed.
   */
  void close();

  /**
   * Mode of USSD message.
   */
  const int USSD_MODE_NOTIFY = 0;
  const int USSD_MODE_REQUEST = 1;

  /**
   * Sends an USSD message.
   *
   * @param ussdMessage USSD message to send.
   */
  void sendUssd(@utf8InCpp String ussdMessage);
}