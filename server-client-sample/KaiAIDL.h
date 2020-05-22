/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

#ifndef _KAIOS_AIDL_TEST_H_
#define _KAIOS_AIDL_TEST_H_

// Setup the test flag.
//#define CONNECTIVITY_TEST 1

#include <android/log.h>
#include <binder/Status.h>

#ifdef CONNECTIVITY_TEST
#  include <b2g/connectivity/IConnectivity.h>
volatile int serverStop = 0;
#endif

#define KAIOS_DEBUG(args...) \
  __android_log_print(ANDROID_LOG_INFO, "KaiOS_AIDL_MAIN", ##args)

#endif
