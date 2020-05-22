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
Please refer `connectivity/ConnectivityServerTest.cpp` for service sample code.

`ConnectivityServerTest` acts as a BnConnectivity and also expose it as a service to system with name `connectivityServerTest`

## Client part
Please refer `KaiAIDL.cpp` Client mode for client sample code.

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
5. Run the daemon and start the server/client test you need.
   kaios_aidl_testing accept one argument to indicate client or server mod.
   1. adb shell kaios_aidl_testing server
   2. adb shell kaios_aidl_testing client
   3. You shall able to see the interactive between server & client,
      Log will dump in android log, you may monitor by :
```
adb logcat |grep -E "KaiOS_AIDL_"
```
