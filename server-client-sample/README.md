<!-- (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG KONG)
 * LIMITED or its affiliate company and may be registered in some jurisdictions.
 * All other trademarks are the property of their respective owners.
 -->

# KaiOS AIDL Testing README
This project is to simulate 3rd party library/daemon use KaiOS AIDL interface.

# Guideline

## Service part
Please refer `generic/classic/ServerTest.cpp` for service sample code.
(or `generic/inherit/InheritServerTest.cpp` for inherit service class)

`ServerTest` acts as a BnConnectivity and also expose it as a service to system with name `KaiOSServerTest`
`IheritServerTest` acts as a inherit class so you may worry less about build break during aidl code merge process.

## Client part
Please refer `generic/Main.cpp` Client mode for client sample code.

This sample code accesses Kai system api `IConnectivity`

1. Unmark one of following build flag in Android.bp to enable test daemon.
   REAL_SERVER_TEST will only activate client mode and try to reach DUT's server.
   CLASSIC_TEST need to implement both client/server and test the interactive between them.
   INHERIT_TEST is simular with CLASSIC_TEST, but test inherit abilities with aidl share library "binder_b2g_stub".
```
// Choose the test case you need.
//        "-DREAL_SERVER_TEST",
//        "-DCLASSIC_TEST",
//        "-DINHERIT_TEST",
```

2. build test binary
```
./build.sh kaios_aidl_testing
```

3. Push this daemon into device directly.
```
   adb root;adb remount;
   adb push out/target/product/<ProjectName>/system/bin/kaios_aidl_testing /system/bin/.
```
4. Run the daemon and start the server/client test you need.
   kaios_aidl_testing accept one argument to indicate client or server mode.
   1. adb shell kaios_aidl_testing server
   2. adb shell kaios_aidl_testing client
   3. You shall able to see the interactive between server & client,
      Log will dump in android log, you may monitor by :
```
adb logcat |grep -E "KaiOS_AIDL_"
```

5. Rewrite test tool to adapt your own module.
Try to check the term under "generic" folder
```
REWRITE_BY_YOURSELF
```
Then you shall find the part which you may replace by your module.
Go through step 1 - 4, you have your own test daemon now!
Please check "connectivity" or "wifi" folder for rewrite sample.

