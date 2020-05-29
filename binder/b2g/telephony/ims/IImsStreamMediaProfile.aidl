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

oneway interface IImsStreamMediaProfile {
  /**
   * Audio information
   */
  const int AUDIO_QUALITY_NONE = 0;
  const int AUDIO_QUALITY_AMR = 1;
  const int AUDIO_QUALITY_AMR_WB = 2;
  const int AUDIO_QUALITY_QCELP13K = 3;
  const int AUDIO_QUALITY_EVRC = 4;
  const int AUDIO_QUALITY_EVRC_B = 5;
  const int AUDIO_QUALITY_EVRC_WB = 6;
  const int AUDIO_QUALITY_EVRC_NW = 7;
  const int AUDIO_QUALITY_GSM_EFR = 8;
  const int AUDIO_QUALITY_GSM_FR = 9;
  const int AUDIO_QUALITY_GSM_HR = 10;
  const int AUDIO_QUALITY_G711U = 11;
  const int AUDIO_QUALITY_G723 = 12;
  const int AUDIO_QUALITY_G711A = 13;
  const int AUDIO_QUALITY_G722 = 14;
  const int AUDIO_QUALITY_G711AB = 15;
  const int AUDIO_QUALITY_G729 = 16;
  const int AUDIO_QUALITY_EVS_NB = 17;
  const int AUDIO_QUALITY_EVS_WB = 18;
  const int AUDIO_QUALITY_EVS_SWB = 19;
  const int AUDIO_QUALITY_EVS_FB = 20;

  /**
   * RTT modes.
   */
  const int RTT_MODE_DISABLED = 0;
  const int RTT_MODE_FULL = 1;

  /**
   * Media directions.
   */
  const int DIRECTION_INVALID = -1;
  const int DIRECTION_INACTIVE = 0;
  const int DIRECTION_RECEIVE = 1;
  const int DIRECTION_SEND = 2;
  const int DIRECTION_SEND_RECEIVE = 3;
}