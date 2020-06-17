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
 *
 */
oneway interface IImsSmsListener {
  /**
   * Triggered when an outgoing SMS message failes to be sent.
   *
   * @param token token provided in IImsMMTelFeature#sendSms.
   * @param messageRef the message reference, which may be
   *        1 byte if it is in FORMAT_3GPP format (see TS.123.040) or
   *        2 bytes if it is in FORMAT_3GPP2 format (see 3GPP2 C.S0015-B).
   * @param status result of sending the SMS.
   *        Possible values: IImsMMTelFeature#SEND_STATUS_*.
   * @param reason failure reason.
   *        The reason is only valid if status is not SEND_STATUS_OK.
   *        Possible values: IImsMMTelFeature#RESULT_*
   * @param networkErrorCode the error code reported by the carrier network if sending this SMS
   *        has resulted in an error or IImsMMTelFeature#RESULT_NO_NETWORK_ERROR if no network error was
   *        generated. See 3GPP TS 24.011 Section 7.3.4 for valid error codes and more information.
   *        The networkErrorCode is only valid if status is not SEND_STATUS_OK.
   */
  void onSendSmsResult(int token, int messageRef, int status, int reason, int networkErrorCode);

  /**
   * Triggered when the status report of the sent message is received.
   *
   * @param token unique token will be used to trigger IImsMMTelFeature#acknowledgeSmsReport
   * @param format the format of message.
   *        Possible values: IImsMMTelFeature#FORMAT_*.
   * @param pdu content of status report.
   */
  void onSmsStatusReportReceived(int token, in @utf8InCpp String format, in byte[] pdu);

  /**
   * Triggered when there is an incoming message.
   * Framework will deliver message to database and the result will be provided by
   * IImsMMTelFeature#acknowledgeSms.
   *
   * @param token unique token will be used to trigger IImsMMTelFeature#acknowledgeSms.
   * @param format the format of message.
   *        Possible values: IImsMMTelFeature#FORMAT_*.
   * @param pdu content of message.
   */
  void onSmsReceived(int token, in @utf8InCpp String format, in byte[] pdu);
}