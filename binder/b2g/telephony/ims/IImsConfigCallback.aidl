/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.telephony.ims;

oneway interface IImsConfigCallback {
    /**
     * The query result of IImsConfig.getConfigInt().
     * @param item IImsConfig.VOICE_OVER_WIFI_MODE, IImsConfig.VOICE_OVER_WIFI_SETTING_ENABLED.
     * @param value Please refer IImsConfig constants.
     */
    void onQueryConfigInt(int item, int value);

    /**
     * @param item Please check item possible values for detail.
     *        Possiable valuse: IImsConfig.VOICE_OVER_WIFI_MODE, IImsConfig.VOICE_OVER_WIFI_SETTING_ENABLED
     * @param value Please check item's possible values for detail.
     *        Possible values: please refer IImsConfig constants.
     * @param status The chante status.
     *        Possible values: IImsConfig.OPERATION_STATUS_*.
     */
    void onSetConfigInt(int item, int value, int status);
}