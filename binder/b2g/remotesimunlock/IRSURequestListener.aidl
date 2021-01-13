/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.remotesimunlock;

oneway interface IRSURequestListener {
    /**
     * ResponseCode types.
     */
    /**
     * Sucess.
     */
    const int RSU_RESP_SUCCESS = 0;

    /**
     * Failure.
     */
    const int RSU_RESP_FAILURE = 1;

    /**
     * Special error type for unlockTimer.
     */
    const int RSU_RESP_TIMER_ERROR = 2;

    /**
     * To notify the result of rsuRequest.
     *
     * @param requestType
     *   One of IRSUService#RSU_TYPE_*.
     * @param token
     *   The index number in callback list.
     * @param responseCode
     *   One of RSU_RESP_*.
     * @param data1
     *   Integer response data from modem.
     * @param data2
     *   Another integer response data from modem.
     * @param data3
     *   Long integer response data from modem.
     * @param responseData
     *   The byte* response data from modem.
     */
    void onResponse(in int requestType, in int token, in int responseCode,
      in int data1, in int data2, in long data3, in byte[] responseData);
}

