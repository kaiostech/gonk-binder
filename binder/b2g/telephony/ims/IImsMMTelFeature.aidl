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

import b2g.telephony.ims.CapabilityChangeRequestParcelable;
import b2g.telephony.ims.IImsCallSession;
import b2g.telephony.ims.IImsCapabilityCallback;
import b2g.telephony.ims.IImsCapabilityListener;
import b2g.telephony.ims.IImsMMTelListener;
import b2g.telephony.ims.IImsSmsListener;
import b2g.telephony.ims.IImsTtyCallback;
import b2g.telephony.ims.IImsUt;
import b2g.telephony.ims.ImsCallProfileParcelable;

interface IImsMMTelFeature {
  const int STATE_UNAVAILABLE = 0;
  const int STATE_INITIALIZING = 1;
  const int STATE_READY = 2;

  /**
   * Voice calling (IR.92).
   * 1 << 0.
   */
  const int CAPABILITY_TYPE_VOICE = 1;

  /**
   * Video (IR.94).
   * 1 << 1.
   */
  const int CAPABILITY_TYPE_VIDEO = 2;

  /**
   * XCAP over Ut for supplementary services. (IR.92).
   * 1 << 2.
   */
  const int CAPABILITY_TYPE_UT = 4;

  /**
   * SMS (IR.92)
   * 1 << 3.
   */
  const int CAPABILITY_TYPE_SMS = 8;

  /**
   * @return The latest feature status
   *         Possible values: STATE_*.
   */
  int getFeatureStatus();

  /**
   * To change capabilities with given capability and radio tech pairs.
   * Change request result will be notified by IImsCapabilityCallback#onChangeCapabilityResponse with status code.
   *
   * @param request The request pairs
   * @param callback The callback to receive change error..
   */
  oneway void changeCapabilities(in CapabilityChangeRequestParcelable request,
                                 IImsCapabilityCallback callback);

  /**
   * To the enable status with given capability and radio tech.
   *
   * @param capability
   *        Possible values: CAPABILITY_TYPE_*.
   * @param radioTech
   *        Possible values: b2g.telephony.ims.RADIO_TECH_*.
   * @return enable state.
   */
  boolean getCapability(int capability, int radioTech);

  /**
   * The modem/network capabilties change events will be notified via listener.
   * @param listener
   */
  oneway void addCapabilityListener(IImsCapabilityListener listener);

  /**
   * To remove modem/network capabilities event listener.
   *
   * @param listener
   */
  oneway void removeCapabilityListener(IImsCapabilityListener listener);

  /**
   * To get UT interface this MMFeature associated with.
   * @return The IMS UT interface object to set/query supplementary service configuration.
   */
  IImsUt getUtInterface();

  /**
   * Sets listener to listen events. Mostly for incoming call at this moment.
   * @param listener the listener to listen events
   */
  oneway void setListener(IImsMMTelListener listener);

  /**
   * To create an outgoing call session.
   *
   * @param profile call profile the call associated with.
   */
  IImsCallSession createCallSession(in ImsCallProfileParcelable profile);

  // SMS APIs
  /**
   * Indicates a 3GPP format SMS message.
   */
  const @utf8InCpp String FORMAT_3GPP = "3gpp";

  /**
   * Indicates a 3GPP2 format SMS message.
   */
  const @utf8InCpp String FORMAT_3GPP2 = "3gpp2";

  /**
   * Message was delivered successfully.
   */
  const int DELIVER_STATUS_OK = 1;

  /**
   * Message was not delivered.
   */
  const int DELIVER_STATUS_ERROR_GENERIC = 2;

  /**
   * Message was not delivered due to lack of memory.
   */
  const int DELIVER_STATUS_ERROR_NO_MEMORY = 3;

  /**
   * Message was not delivered as the request is not supported.
   */
  const int DELIVER_STATUS_ERROR_REQUEST_NOT_SUPPORTED = 4;

  /**
   * Message was sent successfully.
   */
  const int SEND_STATUS_OK = 1;

  /**
   * IMS provider failed to send the message and platform should not retry falling back to sending
   * the message using the radio.
   */
  const int SEND_STATUS_ERROR = 2;

  /**
   * IMS provider failed to send the message and platform should retry again after setting TP-RD
   * bit to high.
   */
  const int SEND_STATUS_ERROR_RETRY = 3;

  /**
   * IMS provider failed to send the message and platform should retry falling back to sending
   * the message using the radio.
   */
  const int SEND_STATUS_ERROR_FALLBACK = 4;

  /**
   * Status Report was set successfully.
   */
  const int STATUS_REPORT_STATUS_OK = 1;

  /**
   * Error while setting status report.
   */
  const int STATUS_REPORT_STATUS_ERROR = 2;

  /**
   * No error.
   */
  const int RESULT_ERROR_NONE    = 0;

  /** Generic failure cause */
  const int RESULT_ERROR_GENERIC_FAILURE    = 1;

  /** Failed because radio was explicitly turned off */
  const int RESULT_ERROR_RADIO_OFF          = 2;

  /** Failed because no pdu provided */
  const int RESULT_ERROR_NULL_PDU           = 3;

  /** Failed because service is currently unavailable */
  const int RESULT_ERROR_NO_SERVICE         = 4;

  /** Failed because we reached the sending queue limit. */
  const int RESULT_ERROR_LIMIT_EXCEEDED     = 5;

  /**
   * Failed because FDN is enabled.
   */
  const int RESULT_ERROR_FDN_CHECK_FAILURE  = 6;

  /** Failed because user denied the sending of this short code. */
  const int RESULT_ERROR_SHORT_CODE_NOT_ALLOWED = 7;

  /** Failed because the user has denied this app ever send premium short codes. */
  const int RESULT_ERROR_SHORT_CODE_NEVER_ALLOWED = 8;

  /**
   * Failed because the radio was not available
   */
  const int RESULT_RADIO_NOT_AVAILABLE = 9;

  /**
   * Failed because of network rejection
   */
  const int RESULT_NETWORK_REJECT = 10;

  /**
   * Failed because of invalid arguments
   */
  const int RESULT_INVALID_ARGUMENTS = 11;

  /**
   * Failed because of an invalid state
   */
  const int RESULT_INVALID_STATE = 12;

  /**
   * Failed because there is no memory
   */
  const int RESULT_NO_MEMORY = 13;

  /**
   * Failed because the sms format is not valid
   */
  const int RESULT_INVALID_SMS_FORMAT = 14;

  /**
   * Failed because of a system error
   */
  const int RESULT_SYSTEM_ERROR = 15;

  /**
   * Failed because of a modem error
   */
  const int RESULT_MODEM_ERROR = 16;

  /**
   * Failed because of a network error
   */
  const int RESULT_NETWORK_ERROR = 17;

  /**
   * Failed because of an encoding error
   */
  const int RESULT_ENCODING_ERROR = 18;

  /**
   * Failed because of an invalid smsc address
   */
  const int RESULT_INVALID_SMSC_ADDRESS = 19;

  /**
   * Failed because the operation is not allowed
   */
  const int RESULT_OPERATION_NOT_ALLOWED = 20;

  /**
   * Failed because of an internal error
   */
  const int RESULT_INTERNAL_ERROR = 21;

  /**
   * Failed because there are no resources
   */
  const int RESULT_NO_RESOURCES = 22;

  /**
   * Failed because the operation was cancelled
   */
  const int RESULT_CANCELLED = 23;

  /**
   * Failed because the request is not supported
   */
  const int RESULT_REQUEST_NOT_SUPPORTED = 24;

  /**
   * Set listener to receive SMS related evnts.
   * @param smsListener listener to receive sms events.
   */
  oneway void setSmsListener(IImsSmsListener smsListener);

  /**
   * To send a sms.
   *
   * @param token unique token that should be used when
   *              triggering callbacks for this specific message.
   * @param messageRef the message reference, which may be
   *        1 byte if it is in FORMAT_3GPP format (see TS.123.040) or
   *        2 bytes if it is in FORMAT_3GPP2 format (see 3GPP2 C.S0015-B).
   * @param format the format of message
   *        Possible values: IImsMMTelFeature#FORMAT_*
   * @param smsc the Short Message Service Center address.
   * @param isRetry whether it is a retry of an already attempted message or not.
   * @param pdu PDU representing the contents of the message.
   */
  oneway void sendSms(int token, int messageRef, @utf8InCpp String format,
                      @utf8InCpp String smsc, boolean isRetry, in byte[] pdu);

  /**
   * This method will be triggered by the platform after
   * IImsMMTelListener#onSmsReceived has been called to deliver the result to the IMS provider.
   *
   * @param token token provided in IImsMMTelListener#onSmsReceived.
   * @param messageRef the message reference, which may be
   *        1 byte if it is in FORMAT_3GPP format (see TS.123.040) or
   *        2 bytes if it is in FORMAT_3GPP2 format (see 3GPP2 C.S0015-B).
   * @param result the result of delivering the message.
   *        Possible values: DELIVER_STATUS_*
   */
  oneway void acknowledgeSms(int token, int messageRef, int result);

  /**
   * This method will be triggered by the platform after
   * IImsMMTelListener#onSmsStatusReportReceived has been called to provide the
   * result to the IMS provider.
   *
   * @param token token provided in IImsMMTelListener#onSmsStatusReportReceived.
   * @param messageRef the message reference, which may be
   *        1 byte if it is in FORMAT_3GPP format (see TS.123.040) or
   *        2 bytes if it is in FORMAT_3GPP2 format (see 3GPP2 C.S0015-B).
   * @param result the result of delivering the message.
   *        Possible values: STATUS_REPORT_STATUS_*.
   */
  oneway void acknowledgeSmsReport(int token, int messageRef, int result);

  /**
   * Returns the SMS format that the ImsService expects.
   *
   * @return sms the expected format. Will be used in IImsMMTelFeature#sendSms.
   *         Possible values: IImsMMTelFeature#FORMAT_*
   */
  @utf8InCpp String getSmsFormat();


  const int TTY_MODE_OFF = 0;
  const int TTY_MODE_FULL = 1;
  const int TTY_MODE_HCO = 2;
  const int TTY_MODE_VCO = 4;

  /**
   * Set UI TTY mode.
   * @param uiTtyMode.
   *        Possible values: TTY_MODE_*.
   * @param callback the callback to receive update result.
   */
  void setUiTtyMode(int uiTtyMode, in IImsTtyCallback callback);

  /**
   * To merge active and hold call.
   * There are 2 possible merge scenarios:
   * case 1: 3-way call, active and hold are both single party call.
   * case 2: 4-way call, active or hold call is conference and merge with single party call.
   * When merge starts, IImsMMTeListener#onCallSessionMergeStarted is called.
   * IImsMMTeListener#onCallSessionMergeComplete is called if merge is succeed.
   * IImsMMTeListener#onCallSessionMergeFailed is called if merge fails.
   */
  oneway void merge(in IImsCallSession host, in IImsCallSession peer);
}
