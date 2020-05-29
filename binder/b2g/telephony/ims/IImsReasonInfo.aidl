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
 * Constants interface.
 */
interface IImsReasonInfo {
  /**
   * The Reason is unspecified.
   */
  const int CODE_UNSPECIFIED = 0;


  // LOCAL

  // IMS -> Telephony
  /**
   * The passed argument is invalid.
   */
  const int CODE_LOCAL_ILLEGAL_ARGUMENT = 101;
  /**
   * The operation was invoked while in an invalid call state.
   */
  const int CODE_LOCAL_ILLEGAL_STATE = 102;
  /**
   * IMS service internal error
   */
  const int CODE_LOCAL_INTERNAL_ERROR = 103;
  /**
   * ImsService has crashed (service connection is lost).
   */
  const int CODE_LOCAL_IMS_SERVICE_DOWN = 106;
  /**
   * No pending incoming call exists
   */
  const int CODE_LOCAL_NO_PENDING_CALL = 107;
  /**
   * IMS Call ended during conference merge process
   */
  const int CODE_LOCAL_ENDED_BY_CONFERENCE_MERGE = 108;

  // IMS -> Telephony
  /**
   * Service unavailable; radio power off
   */
  const int CODE_LOCAL_POWER_OFF = 111;
  /**
   * Service unavailable; low battery
   */
  const int CODE_LOCAL_LOW_BATTERY = 112;
  /**
   * Service unavailable; out of service (data service state)
   */
  const int CODE_LOCAL_NETWORK_NO_SERVICE = 121;
  /**
   * Service unavailable; no LTE coverage
   * (VoLTE is not supported even though IMS is registered)
   */
  const int CODE_LOCAL_NETWORK_NO_LTE_COVERAGE = 122;
  /**
   * Service unavailable; located in roaming area
   */
  const int CODE_LOCAL_NETWORK_ROAMING = 123;
  /**
   * Service unavailable; IP changed
   */
  const int CODE_LOCAL_NETWORK_IP_CHANGED = 124;
  /**
   * Service unavailable; for an unspecified reason
   */
  const int CODE_LOCAL_SERVICE_UNAVAILABLE = 131;
  /**
   * Service unavailable; IMS is not registered
   */
  const int CODE_LOCAL_NOT_REGISTERED = 132;

  // IMS <-> Telephony
  /**
   * Maximum number of simultaneous calls exceeded
   */
  const int CODE_LOCAL_CALL_EXCEEDED = 141;
  // IMS <- Telephony
  /**
   * The call is busy.
   */
  const int CODE_LOCAL_CALL_BUSY = 142;
  /**
   * The Call has been declined locally on this device.
   */
  const int CODE_LOCAL_CALL_DECLINE = 143;
  // IMS -> Telephony
  /**
   * Can not complete call; an SRVCC is in progress.
   */
  const int CODE_LOCAL_CALL_VCC_ON_PROGRESSING = 144;
  /**
   * Can not complete call; resource reservation is failed (QoS precondition)
   */
  const int CODE_LOCAL_CALL_RESOURCE_RESERVATION_FAILED = 145;
  /**
   * VoLTE service can't be provided by the network or remote end, retry the call.
   * Resolve the extra code provided in (EXTRA_CODE_CALL_RETRY_*) if the below code is set
   */
  const int CODE_LOCAL_CALL_CS_RETRY_REQUIRED = 146;
  /**
   * VoLTE service can't be provided by the network temporarily, retry the call.
   */
  const int CODE_LOCAL_CALL_VOLTE_RETRY_REQUIRED = 147;
  /**
   * IMS call is already terminated (in TERMINATED state).
   */
  const int CODE_LOCAL_CALL_TERMINATED = 148;
  /**
   * Call was disconnected because a handover is not feasible due to network conditions.
   */
  const int CODE_LOCAL_HO_NOT_FEASIBLE = 149;
  /**
   * This device does not support IMS.
   * @hide
   */
  const int CODE_LOCAL_IMS_NOT_SUPPORTED_ON_DEVICE = 150;

  /*
   * TIMEOUT (IMS -> Telephony)
   */
  /**
   * 1xx waiting timer is expired after sending INVITE request (MO calls only)
   */
  const int CODE_TIMEOUT_1XX_WAITING = 201;
  /**
   * User didn't answer during call setup operation (MO/MT)
   * MO : 200 OK to INVITE request is not received,
   * MT : No action from user after alerting the call
   */
  const int CODE_TIMEOUT_NO_ANSWER = 202;
  /**
   * User no answer during call update operation (MO/MT)
   * MO : 200 OK to re-INVITE request is not received,
   * MT : No action from user after alerting the call
   */
  const int CODE_TIMEOUT_NO_ANSWER_CALL_UPDATE = 203;

  /**
   * The call was blocked by call barring configuration.
   */
  const int CODE_CALL_BARRED = 240;

  /**
   * The operation is restricted to fixed dialing numbers only.
   */
  const int CODE_FDN_BLOCKED = 241;

  /**
   * Network rejected the emergency call request because IMEI was used as identification
   * and this capability is not supported by the network.
   */
  const int CODE_IMEI_NOT_ACCEPTED = 243;

  //STK CC errors
  /**
   * Stk Call Control modified DIAL request to USSD request.
   */
  const int CODE_DIAL_MODIFIED_TO_USSD = 244;
  /**
   * Stk Call Control modified DIAL request to SS request.
   */
  const int CODE_DIAL_MODIFIED_TO_SS = 245;
  /**
   * Stk Call Control modified DIAL request to DIAL with modified data.
   */
  const int CODE_DIAL_MODIFIED_TO_DIAL = 246;
  /**
   * Stk Call Control modified DIAL request to Video DIAL request.
   */
  const int CODE_DIAL_MODIFIED_TO_DIAL_VIDEO = 247;
  /**
   * Stk Call Control modified Video DIAL request to DIAL request.
   */
  const int CODE_DIAL_VIDEO_MODIFIED_TO_DIAL = 248;
  /**
   * Stk Call Control modified Video DIAL request to Video DIAL request.
   */
  const int CODE_DIAL_VIDEO_MODIFIED_TO_DIAL_VIDEO = 249;
  /**
   * Stk Call Control modified Video DIAL request to SS request.
   */
  const int CODE_DIAL_VIDEO_MODIFIED_TO_SS = 250;
  /**
   * Stk Call Control modified Video DIAL request to USSD request.
   */
  const int CODE_DIAL_VIDEO_MODIFIED_TO_USSD = 251;

  /*
   * STATUSCODE (SIP response code) (IMS -> Telephony)
   */
  // 3xx responses
  /**
   * SIP 3xx response: SIP request is redirected
   */
  const int CODE_SIP_REDIRECTED = 321;
  // 4xx responses
  /**
   * Sip 400 response : Bad Request
   */
  const int CODE_SIP_BAD_REQUEST = 331;
  /**
   * Sip 403 response : Forbidden
   */
  const int CODE_SIP_FORBIDDEN = 332;
  /**
   * Sip 404 response : Not Found
   */
  const int CODE_SIP_NOT_FOUND = 333;
  /**
   * Not supported, because of one of the following:
   * SIP response 415 : Unsupported Media Type,
   * SIP response 416 : Unsupported URI Scheme,
   * SIP response 420 : Bad Extension
   */
  const int CODE_SIP_NOT_SUPPORTED = 334;
  /**
   * SIP response 408 : Request Timeout.
   */
  const int CODE_SIP_REQUEST_TIMEOUT = 335;
  /**
   * SIP response 480 : Temporarily Unavailable
   */
  const int CODE_SIP_TEMPRARILY_UNAVAILABLE = 336;
  /**
   * SIP response 484 : Address Incomplete
   */
  const int CODE_SIP_BAD_ADDRESS = 337;
  /**
   * Returned a busy response, may be one of the following:
   * SIP response 486 : Busy Here,
   * SIP response 600 : Busy Everywhere
   */
  const int CODE_SIP_BUSY = 338;
  /**
   * SIP response 487 : Request Terminated
   */
  const int CODE_SIP_REQUEST_CANCELLED = 339;
  /**
   * Received a not acceptable response, will be one of the following:
   * SIP response 406 : Not Acceptable
   * SIP response 488 : Not Acceptable Here
   * SIP response 606 : Not Acceptable
   */
  const int CODE_SIP_NOT_ACCEPTABLE = 340;
  /**
   * Received a not acceptable response, will be one of the following:
   * SIP response 410 : Gone
   * SIP response 604 : Does Not Exist Anywhere
   */
  const int CODE_SIP_NOT_REACHABLE = 341;
  /**
   * Received another unspecified error SIP response from the client.
   */
  const int CODE_SIP_CLIENT_ERROR = 342;
  /**
   * SIP response 481: Transaction Does Not Exist
   */
  const int CODE_SIP_TRANSACTION_DOES_NOT_EXIST = 343;
  // 5xx responses
  /**
   * SIP response 501 : Server Internal Error
   */
  const int CODE_SIP_SERVER_INTERNAL_ERROR = 351;
  /**
   * SIP response 503 : Service Unavailable
   */
  const int CODE_SIP_SERVICE_UNAVAILABLE = 352;
  /**
   * SIP response 504 : Server Time-out
   */
  const int CODE_SIP_SERVER_TIMEOUT = 353;
  /**
   * Received an unspecified SIP server error response.
   */
  const int CODE_SIP_SERVER_ERROR = 354;
  // 6xx responses
  /**
   * 603 : Decline
   */
  const int CODE_SIP_USER_REJECTED = 361;
  /**
   * Unspecified 6xx error.
   */
  const int CODE_SIP_GLOBAL_ERROR = 362;

  /**
   * Emergency call failed in the modem with a temporary fail cause and should be redialed on this
   * slot.
   */
  const int CODE_EMERGENCY_TEMP_FAILURE = 363;
  /**
   * Emergency call failed in the modem with a permanent fail cause and should not be redialed on
   * this slot. If there are any other slots available for emergency calling, try those.
   */
  const int CODE_EMERGENCY_PERM_FAILURE = 364;

  /**
   * Call failure code during hangup/reject if user marked the call as unwanted.
   *
   * Android Telephony will receive information whether ROBO call feature is supported by the
   * network from modem and propagate the same to AOSP as new ImsCallProfile members. OEMs can
   * check this information and provide an option to the user to mark the call as unwanted.
   */
  const int CODE_SIP_USER_MARKED_UNWANTED = 365;

  /**
   * SIP Response : 405
   * Method not allowed for the address in the Request URI
   */
  const int CODE_SIP_METHOD_NOT_ALLOWED = 366;

  /**
   * SIP Response : 407
   * The request requires user authentication
   */
  const int CODE_SIP_PROXY_AUTHENTICATION_REQUIRED = 367;

  /**
   * SIP Response : 413
   * Request body too large
   */
  const int CODE_SIP_REQUEST_ENTITY_TOO_LARGE = 368;

  /**
   * SIP Response : 414
   * Request-URI too large
   */
  const int CODE_SIP_REQUEST_URI_TOO_LARGE = 369;

  /**
   * SIP Response : 421
   * Specific extension is required, which is not present in the HEADER
   */
  const int CODE_SIP_EXTENSION_REQUIRED = 370;

  /**
   * SIP Response : 422
   * The session expiration field too small
   */
  const int CODE_SIP_INTERVAL_TOO_BRIEF = 371;

  /**
   * SIP Response : 481
   * Request received by the server does not match any dialog or transaction
   */
  const int CODE_SIP_CALL_OR_TRANS_DOES_NOT_EXIST = 372;

  /**
   * SIP Response : 482
   * Server has detected a loop
   */
  const int CODE_SIP_LOOP_DETECTED = 373;

  /**
   * SIP Response : 483
   * Max-Forwards value reached
   */
  const int CODE_SIP_TOO_MANY_HOPS = 374;

  /**
   * SIP Response : 485
   * Request-URI is ambiguous
   *
   */
  const int CODE_SIP_AMBIGUOUS = 376;

  /**
   * SIP Response : 491
   * Server has pending request for same dialog
   */
  const int CODE_SIP_REQUEST_PENDING = 377;

  /**
   * SIP Response : 493
   * The request cannot be decrypted by recipient
   */
  const int CODE_SIP_UNDECIPHERABLE = 378;

  /**
   * MEDIA (IMS -> Telephony)
   */
  /**
   * Media resource initialization failed
   */
  const int CODE_MEDIA_INIT_FAILED = 401;
  /**
   * RTP timeout (no audio / video traffic in the session)
   */
  const int CODE_MEDIA_NO_DATA = 402;
  /**
   * Media is not supported; so dropped the call
   */
  const int CODE_MEDIA_NOT_ACCEPTABLE = 403;
  /**
   * Unspecified media related error.
   */
  const int CODE_MEDIA_UNSPECIFIED = 404;

  /*
   * USER
   */
  // Telephony -> IMS
  /**
   * User triggers the call to be terminated.
   */
  const int CODE_USER_TERMINATED = 501;
  /**
   * No action was taken while an incoming call was ringing.
   */
  const int CODE_USER_NOANSWER = 502;
  /**
   * User ignored an incoming call.
   */
  const int CODE_USER_IGNORE = 503;
  /**
   * User declined an incoming call.
   */
  const int CODE_USER_DECLINE = 504;
  /**
   * Device declined/ended a call due to a low battery condition.
   */
  const int CODE_LOW_BATTERY = 505;
  /**
   * Device declined a call due to a blacklisted caller ID.
   */
  const int CODE_BLACKLISTED_CALL_ID = 506;
  // IMS -> Telephony
  /**
   * The call has been terminated by the network or remote user.
   */
  const int CODE_USER_TERMINATED_BY_REMOTE = 510;
  /**
  * Upgrade Downgrade request rejected by
  * Remote user if the request is MO initiated
  * Local user if the request is MT initiated
  */
  const int CODE_USER_REJECTED_SESSION_MODIFICATION = 511;

  /**
  * Upgrade Downgrade request cancelled by the user who initiated it
  */
  const int CODE_USER_CANCELLED_SESSION_MODIFICATION = 512;

  /**
   * UPGRADE DOWNGRADE operation failed
   * This can happen due to failure from SIP/RTP/SDP generation or a Call end is
   * triggered/received while Reinvite is in progress.
   */
  const int CODE_SESSION_MODIFICATION_FAILED = 1517;

  /*
   * UT
   */
  /**
   * UT is currently not supported on this device.
   */
  const int CODE_UT_NOT_SUPPORTED = 801;
  /**
   * UT services are currently not available on this device.
   */
  const int CODE_UT_SERVICE_UNAVAILABLE = 802;
  /**
   * The requested UT operation is not allowed.
   */
  const int CODE_UT_OPERATION_NOT_ALLOWED = 803;
  /**
   * The UT request resulted in a network error.
   */
  const int CODE_UT_NETWORK_ERROR = 804;
  /**
   * The password entered for UT operations does not match the stored password.
   */
  const int CODE_UT_CB_PASSWORD_MISMATCH = 821;
  //STK CC errors
  /**
   * Sim Toolkit Call Control modified the UT operation to a dial command.
   */
  const int CODE_UT_SS_MODIFIED_TO_DIAL = 822;
  /**
   * Sim Toolkit Call Control modified the UT operation to a USSD command.
   */
  const int CODE_UT_SS_MODIFIED_TO_USSD = 823;
  /**
   * Sim Toolkit Call Control modified the UT operation to another supplementary service command.
   */
  const int CODE_UT_SS_MODIFIED_TO_SS = 824;
  /**
   * Sim Toolkit Call Control modified the UT operation to a video call dial command.
   */
  const int CODE_UT_SS_MODIFIED_TO_DIAL_VIDEO = 825;

  /**
   * Supplementary services (HOLD/RESUME) failure error codes.
   * Values for Supplemetary services failure - Failed, Cancelled and Re-Invite collision.
   */

  /**
   * Supplementary Services (HOLD/RESUME) - the command failed.
   */
  const int CODE_SUPP_SVC_FAILED = 1201;
  /**
   * Supplementary Services (HOLD/RESUME) - the command was cancelled.
   */
  const int CODE_SUPP_SVC_CANCELLED = 1202;
  /**
   * Supplementary Services (HOLD/RESUME) - the command resulted in a re-invite collision.
   */
  const int CODE_SUPP_SVC_REINVITE_COLLISION = 1203;
}