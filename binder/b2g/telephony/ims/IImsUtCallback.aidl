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

import b2g.telephony.ims.ImsCallForwardInfoParcelable;
import b2g.telephony.ims.ImsReasonInfoParcelable;
import b2g.telephony.ims.ImsClirResponseParcelable;
import b2g.telephony.ims.ImsSsInfoParcelable;

oneway interface IImsUtCallback {
    /**
     * Notifies the call forward query result.
     * @param id The request id.
     * @param cfInfos The call forward results.
     */
    void onCallForwardQueried(int id, in ImsCallForwardInfoParcelable[] cfInfos);

    /**
     * Notifies the result of supplementary service configuration updated.
     * @param id The request id.
     */
    void onUtConfigurationUpdated(int id);

    /**
     * @param id The request id.
     * @param error
     */
    void onUtConfigurationUpdateFailed(int id, in ImsReasonInfoParcelable error);

    /**
     * @param id
     * @param infos
     */
    void onCallBarringQueried(int id, in ImsSsInfoParcelable cbInfo);

    /**
     * @param id
     * @param cwInfos
     */
    void onCallWaitingQueried(int id, in ImsSsInfoParcelable cwInfo);

    /**
     * Notified when query failed.
     * @param id The request i.
     * @param error
     */
    void utConfigurationQueryFailed(int id, in ImsReasonInfoParcelable error);

    /**
     * @param id
     * @param clirStatus
     */
    void onClirQueried(int id, in ImsClirResponseParcelable clirStatus);
}