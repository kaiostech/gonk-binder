/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.telephony.ims;

parcelable ImsReasonInfoParcelable {
    /**
     * For the main reason code.
     * Possible values: TBD.
     */
    int code;

    /**
     * For the extra information code.
     * Possible values: TBD.
     */
    int extraCode;

    /**
     * For the extra message of the reason.
     */
    @utf8InCpp String extraMessage;
}