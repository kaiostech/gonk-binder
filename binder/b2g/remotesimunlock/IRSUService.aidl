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
     * Request types.
     */
    /**
     * Update blob.
     */
    const int RSU_TYPE_UPDATE_BLOB = 0;
    /**
     * Get shared key.
     */
    const int RSU_TYPE_QUERY_SHARED_KEY = 1;

    /**
     * Generate HMAC.
     */
    const int RSU_TYPE_GENERATE_HMAC = 2;

    /**
     * Get major/minor version.
     */
    const int RSU_TYPE_QUERY_BLOB_VERSION = 3;

    /**
     * Get current lock status.
     */
    const int RSU_TYPE_QUERY_STATUS_CODE = 4;

    /**
     * Generate request blob.
     */
    const int RSU_TYPE_GENERATE_REQUEST_BLOB = 5;

    /**
     * Start timer.
     */
    const int RSU_TYPE_START_UNLOCK_TIMER = 6;

    /**
     * Stop timer.
     */
    const int RSU_TYPE_STOP_UNLOCK_TIMER = 7;

    /**
     * To set listener interface for RSU.
     *
     * @param listener
     *   The listener to receive operate result.
     */
    void addRSUListener(in IRSURequestListener listener);

    /**
     * To remove listener interface for RSU.
     *
     * @param listener
     *   The listener to receive operate result.
     */
    void removeRSUListener(in IRSURequestListener listener);

    /**
     * To send request blob to modem.
     *
     * @param requestType
     *   One of RSU_TYPE_*
     * @param token
     *   The index number in callback list.
     * @param data
     *   The array data in byte for lock/unlock.
     */
    void rsuRequest(in int requestType, in int token, in byte[] data);

    /**
     * To send private rsu request blob to modem.
     *
     * @param requestType
     *   Private requestType belong to special Platform.
     * @param token
     *   The index number in callback list.
     * @param data
     *   The array data in byte for lock/unlock.
     */
    void rsuExtraRequest(in int requestType, in int token, in byte[] data);
}
