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
 * The media profile a call session associated with.
 * This is mostly designed for video call, codec.
 * Please see IImsStreamMediaProfile.aidl for constants definition.
 */
parcelable ImsStreamMediaProfileParcelable {

  /**
   * The audio quality.
   * Possible values: IImsStreamMediaProfile#AUDIO_QUALITY_*.
   */
  int audioQuality;

  /**
   * Current RTT mode.
   * Possible values: IImsStreamMediaProfile#RTT_MODE_*.
   */
  int rttMode;

  /**
   * RTT audio speech indication.
   */
  boolean isReceivingRttAudio;

  // Currently, Kai does not expose video quality info to user.
  // int videoQuality;

  /**
   * Current audio direction.
   * Mostly used for MO call ringback tone indication.
   * Possible values: IImsStreamMediaProfile#DIRECTION_INVALID.
   */
  int audioDirection;
}