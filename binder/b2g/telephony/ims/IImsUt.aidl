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

import b2g.telephony.ims.IImsUtCallback;

/**
 * Provide the UT interface to set/query supplementary service configuration.
 */
interface IImsUt {
  /**
   * For the status of service registration or activation/deactivation.
   */
  const int STATUS_NOT_REGISTERED = -1;
  const int STATUS_DISABLED = 0;
  const int STATUS_ENABLED = 1;

  /**
   * Call forwarding is not active for any service class.
   */
  const int CF_STATUS_NOT_ACTIVE = 0;

  /**
   * Call forwarding is active for one or more service classes.
   */
  const int CF_STATUS_ACTIVE = 1;

  /**
   * The address defined in {@link #getNumber()} is in an unknown format.
   *
   * See TS 27.007, section 7.11 for more information.
   */
  const int TYPE_OF_ADDRESS_UNKNOWN = 0x81;
  /**
   * The address defined in {@link #getNumber()} is in E.164 international format, which includes
   * international access code "+".
   *
   * See TS 27.007, section 7.11 for more information.
   */
  const int TYPE_OF_ADDRESS_INTERNATIONAL = 0x91;

  /**
   * No call forwarding service class defined.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_NONE = 0;

  /**
   * Service class flag for voice telephony.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_VOICE = 1;

  /**
   * Service class flag for all data bearers (including
   * {@link #SERVICE_CLASS_DATA_CIRCUIT_SYNC,
   * {@link #SERVICE_CLASS_DATA_CIRCUIT_ASYNC}, {@link #SERVICE_CLASS_PACKET_ACCESS},
   * {@link #SERVICE_CLASS_PAD}}) if supported by the carrier.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_DATA = 2;
  /**
   * Service class flag for fax services.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_FAX = 4;
  /**
   * Service class flag for SMS services.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_SMS = 8;
  /**
   * Service class flag for the synchronous bearer service.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_DATA_CIRCUIT_SYNC = 16;

  /**
   * Service class flag for the asynchronous bearer service.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_DATA_CIRCUIT_ASYNC = 32;

  /**
   * Service class flag for the packet access bearer service.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_DATA_PACKET_ACCESS = 64;

  /**
   * Service class flag for the Packet Assembly/Disassembly bearer service.
   *
   * See TS 27.007 7.11 (+CCFC) and 7.4 (CLCK)
   */
  const int SERVICE_CLASS_DATA_PAD = 128;

  /**
   * Sets callback to receive set/query results.
   * @param callback the callback to receive set/query response.
   */
  oneway void setCallback(in IImsUtCallback callback);

  /**
   * Actions
   */
  const int ACTION_DEACTIVATION = 0;
  const int ACTION_ACTIVATION = 1;
  const int ACTION_REGISTRATION = 3;
  const int ACTION_ERASURE = 4;
  const int ACTION_INTERROGATION = 5;

  /**
   * CDIV (Communication Diversion, 3GPP TS 24.604)
   */
  const int CDIV_CF_UNCONDITIONAL = 0;
  const int CDIV_CF_BUSY = 1;
  const int CDIV_CF_NO_REPLY = 2;
  const int CDIV_CF_NOT_REACHABLE = 3;
  // For CS service code: 002
  const int CDIV_CF_ALL = 4;
  // For CS service code: 004
  const int CDIV_CF_ALL_CONDITIONAL = 5;
  // It's only supported in the IMS service (CS does not define it).
  // IR.92 recommends that an UE activates both the CFNRc and the CFNL
  // (CDIV using condition not-registered) to the same target.
  const int CDIV_CF_NOT_LOGGED_IN = 6;

  /**
   * To retrieve call forward configuration.
   * The result will be notified via IImsUtCallback.onCallForwardQueried.
   * @param condition, possible values, CDIV_CF_*.
   * @param number Not used.
   * @return the request id.
   *         If return value < 0, means there is an error.
   */
  int queryCallForward(int condition, @utf8InCpp String number);

  /**
   * @param action is one of IImsUt.ACTION_*.
   * @param condition is one of IImsUt.CDIV_CF_*.
   * @param number Phone number of forwarding address.
   * @param serviceClass Conbination of IImsUt.SERVICE_CLASS_*
   * @param timeSeconds when condiction `IImsUt.CDIV_CF_NO_REPLY` is enabled,
   *        this gives the time in secodns to wait before call is forwarded.
   * @return The request id.
   *         If return value < 0, means there is an error.
   */
  int updateCallForward(int action, int condition, @utf8InCpp String number,
                          int serviceClass, int timeSeconds);

  /**
   * CB (Communication Barring, 3GPP TS 24.611)
   */
  // Barring of All Incoming Calls
  const int CB_BAIC = 1;
  // Barring of All Outgoing Calls
  const int CB_BAOC = 2;
  // Barring of Outgoing International Calls
  const int CB_BOIC = 3;
  // Barring of Outgoing International Calls - excluding Home Country
  const int CB_BOIC_EXHC = 4;
  // Barring of Incoming Calls - when roaming
  const int CB_BIC_WR = 5;
  // Barring of Anonymous Communication Rejection (ACR) - a particular case of ICB service
  const int CB_BIC_ACR = 6;
  // Barring of All Calls
  const int CB_BA_ALL = 7;
  // Barring of Outgoing Services (Service Code 333 - 3GPP TS 22.030 Table B-1)
  const int CB_BA_MO = 8;
  // Barring of Incoming Services (Service Code 353 - 3GPP TS 22.030 Table B-1)
  const int CB_BA_MT = 9;
  // Barring of Specific Incoming calls
  const int CB_BS_MT = 10;

  /**
   * @param type is one of IImsUt.CB_*.
   * @param serviceClass is one of IImsUt.SERVICE_CLASS*.
   * @return The request id.
   *         If return value < 0, means there is an error.
   */
  int queryCallBarring(int cbType, int serviceClass);

  /**
   * Updates the configuration of the call barring for specified service class with password.
   * @param cbType is one of IImsUt.CB_*.
   * @param action is one of IImsUt.ACTION_*.
   * @param barrList the number to be bared. If null is give, apply to all calls.
   * @param serviceClass is one of IImsUt.SERVICE_CLASS_*.
   * @param password call barring password. Could be null or "" is no password specified.
   * @return The request id.
   */
  int updateCallBarring(int cbType, int action, in @utf8InCpp String[] barrList,
                        int serviceClass, @utf8InCpp String password);

  /**
   * To query call waiting status.
   * @return The request id.
   */
  int queryCallWaiting();

  /**
   * To update call waiting status
   * @param enable boolean to indicates the desired call waiting status.
   * @param serviceClass is one of IImsUt.SERVICE_CLASS_*.
   * @return The request id.
   */
  int updateCallWaiting(boolean enable, int serviceClass);

  /**
   * Calling line identification restriction (CLIR) is set to the default according to the
   * subscription of the CLIR service.
   *
   * See TS 27.007, section 7.7 for more information.
   */
  const int CLIR_OUTGOING_DEFAULT = 0;
  /**
   * Activate Calling line identification restriction for outgoing calls.
   *
   * See TS 27.007, section 7.7 for more information.
   */
  const int CLIR_OUTGOING_INVOCATION = 1;
  /**
   * Deactivate Calling line identification restriction for outgoing calls.
   *
   * See TS 27.007, section 7.7 for more information.
   */
  const int CLIR_OUTGOING_SUPPRESSION = 2;

  /**
   * Calling line identification restriction is currently not provisioned.
   *
   * See TS 27.007, section 7.7 for more information.
   */
  const int CLIR_STATUS_NOT_PROVISIONED = 0;
  /**
   * Calling line identification restriction is currently provisioned in permanent mode.
   *
   * See TS 27.007, section 7.7 for more information.
   */
  const int CLIR_STATUS_PROVISIONED_PERMANENT = 1;
  /**
   * Calling line identification restriction is currently unknown, e.g. no network, etc.
   *
   * See TS 27.007, section 7.7 for more information.
   */
  const int CLIR_STATUS_UNKNOWN = 2;
  /**
   * Calling line identification restriction temporary mode, temporarily restricted.
   *
   * See TS 27.007, section 7.7 for more information.
   */
  const int CLIR_STATUS_TEMPORARILY_RESTRICTED = 3;
  /**
   * Calling line identification restriction temporary mode, temporarily allowed.
   *
   * See TS 27.007, section 7.7 for more information.
   */
  const int CLIR_STATUS_TEMPORARILY_ALLOWED = 4;

  /**
   * To query Calling Line Id Restriction status.
   * @return The request id.
   */
  int queryCLIR();

  /**
   * To update Calling Line Id Restriction status.
   * @param clirMode is one of IImsUt.CLIR_OUTGOING_*.
   * @return The request id.
   */
  int updateCLIR(int clirMode);

  /**
   * KaiOS doesn't support this yet.
   * Retrieves the CLIP call setting.
   */
  // int queryCLIP();

  /**
   * KaiOS doesn't support this yet.
   * Updates the configuration of the CLIP supplementary service.
   */
  // int updateCLIP(boolean enable);

  /**
   * KaiOS doesn't support this yet.
   * Retrieves the COLR call setting.
   */
  // int queryCOLR();

  /**
   * KaiOS doesn't support this yet.
   * Updates the configuration of the COLR supplementary service.
   */
  // int updateCOLR(int presentation);


  /**
   * KaiOS doesn't support this yet.
   * Retrieves the COLP call setting.
   */
  // int queryCOLP();

  /**
   * KaiOS doesn't support this yet.
   * Updates the configuration of the COLP supplementary service.
   */
  // int updateCOLP(boolean enable);
}