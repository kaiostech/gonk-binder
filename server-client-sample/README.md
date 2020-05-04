<!-- (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG KONG)
 * LIMITED or its affiliate company and may be registered in some jurisdictions.
 * All other trademarks are the property of their respective owners.
 -->

# KaiOS AIDL Testing README
This project is to simulate 3rd party library/daemon use KaiOS AIDL interface.

# GuidelineClient

## Service part
Please refer `connectivity/ConnectivityEventTest.cpp` for service sample code.

`ConnectivityEventTest` acts as a BnConnectivityEventListener and also expose it as a service to system with name `connectivityEventTest`

## Client part
Please refer `KaiAIDL.cpp` for client sample code.

This sample code accesses Kai system api `IConnectivity`

1. Place this folder under any place which may use Android.bp such as $DIR/external.

2. Unmark following define in KaiAIDL.h to enable client test.
```
//#define CONNECTIVITY_TEST 1
```

3. Initialize the environment with `envsetup.sh` script
```
source build/envsetup.sh
```

3. Make test binary
```
make kaios_aidl_testing
```

4. Push this daemon into device directly.
```
   adb root;adb remount;
   adb push out/target/product/<ProjectName>/system/bin/kaios_aidl_testing /system/bin/.
```
5. Run the daemon and start the test you need.
   1. adb shell kaios_aidl_testing
   2. Log will dump in android log, you may monitor by :
```
adb logcat |grep -E "KaiOS_AIDL_"
```
