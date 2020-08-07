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

import b2g.telephony.ims.ImsCallProfileParcelable;
import b2g.telephony.ims.ImsConferenceParticipantParcelable;
import b2g.telephony.ims.ImsReasonInfoParcelable;
import b2g.telephony.ims.ImsSuppServiceNotificationParcelable;
import b2g.telephony.ims.ImsStreamMediaProfileParcelable;

oneway interface IImsCallSessionListener {
  /**
   * Notifies call session is progressing. (Alerting).
   *
   * @param profile the stream media profile this call session associated with.
   */
  void onCallSessionProgressing(in ImsStreamMediaProfileParcelable mediaProfile);

  /**
   * Notifies call session is started. (IN_CALL).
   *
   * @param profile call profile this call session associated with.
   */
  void onCallSessionStarted(in ImsCallProfileParcelable profile);

  /**
   * Notifies call session start failed. (ENDED)
   *
   * @param reasonInfo start failure reason info.
   */
  void onCallSessionStartFailed(in ImsReasonInfoParcelable reasonInfo);

  /**
   * Notifies call session is terminated. (ENDED)
   *
   * @param reasonInfo termination reason info.
   */
  void onCallSessionTerminated(in ImsReasonInfoParcelable reasonInfo);

  /**
   * Notifies call session hold request is succeed. (HELD).
   *
   * @param profile call profile this call session associated with.
   */
  void onCallSessionHeld(in ImsCallProfileParcelable profile);

  /**
   * Notifies call session hold request is failed.
   *
   * @param reasonInfo hold failure reason info.
   */
  void onCallSessionHoldFailed(in ImsReasonInfoParcelable reasonInfo);

  /**
   * Notifies call session resume request is succeed.
   *
   * @param profile call profile this call session associated with.
   */
  void onCallSessionResumed(in ImsCallProfileParcelable profile);

  /**
   * Notifies call session resume request is failed.
   *
   * @param reasonInfo resume failure reason info.
   */
  void onCallSessionResumeFailed(in ImsReasonInfoParcelable reasonInfo);

  /**
   * Notifies remote hold this call session.
   *
   * @param profile The profile associted with this session.
   */
  void onCallSessionHoldReceived(in ImsCallProfileParcelable profile);

  /**
   * Notifies remote resume a call which is previously held by remote.
   *
   * @param profile The profile associted with this session.
   */
  void onCallSessionResumeReceived(in ImsCallProfileParcelable profile);

  /**
   * Notified when call updated.
   */
  void onCallSessionUpdated(in ImsCallProfileParcelable profile);

  /**
   * Device received RTT modify request from remote.
   * @param toProfile call profile with updated attribute.
   */
  void onCallSessionRttModifyRequestReceived(in ImsCallProfileParcelable toProfile);

  /**
   * Device issued RTT modify request and received remote response.
   * @param status remote response.
   *        Possible values: IImsCallSession#SESSION_MODIFY_REQUEST_*.
   */
  void onCallSessionRttModifyResponseReceived(in int status);

  /**
   * Device received RTT message from remote.
   * @param rttMessage rtt message.
   */
  void onCallSessionRttMessageReceived(in @utf8InCpp String rttMessage);

  /**
   * RTT audio indicatin has been changed while in a call.
   * @param mediaProfile updated mediaProfile
   */
  void onCallSessionRttAudioIndicatorChanged(in ImsStreamMediaProfileParcelable mediaProfile);

  /**
   * Notifies the supplementary service information for this session.
   */
  void onCallSessionSuppServiceReceived(in ImsSuppServiceNotificationParcelable suppSrvNotification);

  /**
   * Notifies the TTY mode change by remote.
   * @param mode new tty mode.
   *        Possible values: IImsMMTelFeature#TTY_MODE_*.
   */
  void onCallSessionTtyModeReceived(in int mode);

  /**
   * Notifies the call session may handover from one network type to another.
   *
   * @param srcTech the source radio technology.
   *        Possible values: IImsRegistration#RADIO_TECH_*.
   * @param targetTech the target radio technology.
   *        Possible values: IImsRegistration#RADIO_TECH_*.
   */
  void onCallSessionMayHandover(int srcTech, int targetTech);

  /**
   * Notifies call session's access techonology has changed.
   *
   * @param srcTech the source radio technology.
   *        Possible values: IImsRegistration#RADIO_TECH_*.
   * @param targetTech the target radio technology.
   *        Possible values: IImsRegistration#RADIO_TECH_*.
   */
  void onCallSessionHandover(int srcTech, int targetTech);

  /**
   * Notifies call session's access techonology change has failed.
   * @param srcTech the source radio technology.
   *        Possible values: IImsRegistration#RADIO_TECH_*.
   * @param targetTech the target radio technology.
   *        Possible values: IImsRegistration#RADIO_TECH_*.
   * @param reasonInfo the fail reason.
   *        The reason code are mostly IImsRasonInfo#CODE_UNSPECIFIED and
   *        IImsRasonInfo#CODE_CALL_DROP_IWLAN_TO_LTE_UNAVAILABLE.
   */
  void onCallSessionHandoverFailed(int srcTech, int targetTech, in ImsReasonInfoParcelable reasonInfo);

  /**
   * Notifies conference state change info in the conference call.
   *
   * @param participants the update conference state info.
   */
  void onCallSessionConferenceStateUpdated(in ImsConferenceParticipantParcelable[] participants);

  /**
   * Notifies remove participants from conference request has been delievered to conference server.
   * onCallSessionConferenceStateUpdated is expected to refresh the participants list.
   */
  void onCallSessionRemoveParticipantsRequestDelivered();

  /**
   * Notifies remove participants from conerence request has been delivered to conference server and failed.
   */
  void onCallSessionRemoveParticipantsRequestFailed(in ImsReasonInfoParcelable reasonInfo);

  /**
   * Notifies call transfer request success.
   */
  void onCallSessionTransferred();

  /**
   * Notifies call transfer request failed.
   * @param reasonInfo failure reason.
   */
  void onCallSessionTransferFailed(in ImsReasonInfoParcelable reasonInfo);
}