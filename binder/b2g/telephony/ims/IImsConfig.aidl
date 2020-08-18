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

import b2g.telephony.ims.IImsConfigCallback;

/**
 * Provides APIs to access IMS configuration.
 */
interface IImsConfig {
    /**
     * Config values: Voice over Wi-Fi mode.
     */
    const int WIFI_MODE_WIFI_ONLY = 0;
    const int WIFI_MODE_CELLULAR_PREFERRED = 1;
    const int WIFI_MODE_WIFI_PREFERRED = 2;

    /**
     * Config item: Voice over Wi-Fi mode.
     * Possible values: WIFI_MODE_*.
     */
    const int VOICE_OVER_WIFI_MODE = 27;

    /**
     * Config item: RTT status setting.
     * Possibel values: 0: disabled, 1: enabled.
     */
    const int RTT_SETTING_ENABLED = 66;

    /**
     * Config setter result sttus codes.
     */
    const int OPERATION_STATUS_UNKNOWN = -1;
    const int OPERATION_STATUS_SUCCESS = 0;
    const int OPERATION_STATUS_FAILED =  1;
    const int OPERATION_STATUS_UNSUPPORTED_CAUSE_NONE = 2;
    const int OPERATION_STATUS_UNSUPPORTED_CAUSE_RAT = 3;
    const int OPERATION_STATUS_UNSUPPORTED_CAUSE_DISABLED = 4;

    /**
     * To get integer configuration.
     * @param item the item to be quried.
     * @param callback To receive query result.
   */
    void queryConfigInt(int item, in IImsConfigCallback callback);

    /**
     * To setup configuration
     * @param item the config item to be updated.
     * @param value the update value.
     */
    void setConfigInt(int item, int value, in IImsConfigCallback callback);
}