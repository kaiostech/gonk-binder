/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _AIDL_TEST_H_
#define _AIDL_TEST_H_

#include <android/log.h>
#include <binder/Status.h>

#if defined(CLASSIC_TEST) || defined(INHERIT_TEST) || defined(REAL_SERVER_TEST)
volatile int serverStop = 0;
#endif

#endif  // _AIDL_TEST_H_
