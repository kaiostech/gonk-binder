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

oneway interface IImsConferenceParticipant {
  /**
   * status-type
   * STATUS_PENDING : Endpoint is not yet in the session, but it is anticipated that he/she will
   *      join in the near future.
   * STATUS_DIALING_OUT : Focus has dialed out to connect the endpoint to the conference,
   *      but the endpoint is not yet in the roster (probably being authenticated).
   * STATUS_DIALING_IN : Endpoint is dialing into the conference, not yet in the roster
   *      (probably being authenticated).
   * STATUS_ALERTING : PSTN alerting or SIP 180 Ringing was returned for the outbound call;
   *      endpoint is being alerted.
   * STATUS_ON_HOLD : Active signaling dialog exists between an endpoint and a focus,
   *      but endpoint is "on-hold" for this conference, i.e., he/she is neither "hearing"
   *      the conference mix nor is his/her media being mixed in the conference.
   * STATUS_CONNECTED : Endpoint is a participant in the conference. Depending on the media policies,
   *      he/she can send and receive media to and from other participants.
   * STATUS_DISCONNECTING : Focus is in the process of disconnecting the endpoint
   *      (e.g. in SIP a DISCONNECT or BYE was sent to the endpoint).
   * STATUS_DISCONNECTED : Endpoint is not a participant in the conference, and no active dialog
   *      exists between the endpoint and the focus.
   * STATUS_MUTED_VIA_FOCUS : Active signaling dialog exists beween an endpoint and a focus and
   *      the endpoint can "listen" to the conference, but the endpoint's media is not being
   *      mixed into the conference.
   * STATUS_CONNECT_FAIL : Endpoint fails to join the conference by rejecting the conference call.
   */
  const int STATUS_PENDING = 0;
  const int STATUS_DIALING_OUT = 1;
  const int STATUS_DIALING_IN = 2;
  const int STATUS_ALERTING = 3;
  const int STATUS_ON_HOLD = 4;
  const int STATUS_CONNECTED = 5;
  const int STATUS_DISCONNECTING = 6;
  const int STATUS_DISCONNECTED = 7;
  const int STATUS_MUTED_VIA_FOCUS = 8;
  const int STATUS_CONNECT_FAIL = 9;
  const int STATUS_SEND_ONLY = 10;
  const int STATUS_SEND_RECV = 11;
}