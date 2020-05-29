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
import b2g.telephony.ims.ImsReasonInfoParcelable;
import b2g.telephony.ims.ImsStreamMediaProfileParcelable;

oneway interface IImsCallSessionListener {
  /**
   * Notifies call session is progressing. (Alerting).
   *
   * @param profile the stream media profile this call session associated with.
   */
  void onCallSessionProgressing(in ImsStreamMediaProfileParcelable profile);

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
   * Notifies the result of call upgrade / downgrade or other updates.
   * @param profile the updated call profile.
   */
  void callSessionUpdated(in ImsCallProfileParcelable profile);

  /* TBD, most likely for video call.
   * Notifies the call upgrade / downgrade or other update request is failed.
   *
   * @param reasonInfo the failure reason info.
   */
  // void callSessionUpdateFailed(in ImsReasonInfoParcelable reasonInfo);

  /* TBD, most likely for video call.
   * Notifies call upgrade / download or other update request been requested from remote site.
   *
   * @param profile the requested call profile.
   */
  //void callSessionUpdateReceived(in ImsCallProfileParcelable profile);
}