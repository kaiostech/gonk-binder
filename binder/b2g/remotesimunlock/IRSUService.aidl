/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.remotesimunlock;

import b2g.remotesimunlock.IRSURequestListener;

oneway interface IRSUService {

    const String RSU_SERVICE_MANAGER = "rsuservice";

    /**
     * RequestType types for setUnlockTimer.
     */
    /**
     * Start timer.
     */
    const int START_UNLOCK_TIMER = 1;

    /**
     * Stop timer.
     */
    const int STOP_UNLOCK_TIMER = 2;

    /**
     * To set listener interface for RSU.
     * If remove listener, param listener will be NULL.
     *
     * @param listener
     *   The listener to receive operate result.
     */
    void setRSUListener(in IRSURequestListener listener);

    /**
     * To send lock/unlock blob to modem.
     *
     * @param token
     *   The index number in callback list.
     * @param data
     *   The array data in byte for lock/unlock.
     */
    void updateBlob(in int token, in byte[] data);

    /**
     * To get shared key from modem.
     *
     * @param token
     *   The index number in callback list.
     */
    void querySharedKey(in int token);

    /**
     * To let modem generate and provide HMAC based on the input value.
     *
     * @param token
     *   The index number in callback list.
     * @param data
     *   The input data for HMAC.
     */
    void generateHMAC(in int token, in byte[] data);

    /**
     * To get major/minor version of blob.
     *
     * @param token
     *   The index number in callback list.
     */
    void queryBlobVersion(in int token);

    /**
     * To get current lock status from Modem.
     *
     * @param token
     *   The index number in callback list.
     */
    void querySimlockStatusCode(in int token);

    /**
     * To let Modem generate a request blob.
     *
     * @param token
     *   The index number in callback list.
     */
    void generateRequestBlob(in int token);

    /**
     * To let Modem start/stop a timer of allowing temporary connectivity.
     *
     * @param token
     *   The index number in callback list.
     * @param requestType
     *   START_UNLOCK_TIMER
     *   STOP_UNLOCK_TIMER
     */
    void setUnlockTimer(in int token, in int requestType);
}
