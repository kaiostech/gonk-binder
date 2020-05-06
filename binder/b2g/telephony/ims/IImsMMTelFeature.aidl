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
import b2g.telephony.ims.IImsCapabilityCallback;
import b2g.telephony.ims.IImsCapabilityListener;
import b2g.telephony.ims.IImsUt;

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
     * If any subset of request succeed, the succeed signal will be notified via
     *   IImsCapabilityCall.onChangeCapabilityConfigurationSuccess.
     * If any subset of request failed, the failed detail will be notified via
     *  IImsCapabilityCallback.onChangeCapabilityConfigurationError.
     *
     * @param request The request pairs
     * @param callback The callback to receive change error..
     */
    oneway void changeCapabilities(in CapabilityChangeRequestParcelable request,
                                   IImsCapabilityCallback callback);

    /**
     * To the enable status with given capability and radio tech.
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
     * @param listener
     */
    oneway void removeCapabilityListener(IImsCapabilityListener listener);

    /**
     * @return The IMS UT interface object to set/query supplementary service configuration.
     */
    IImsUt getUtInterface();
}
