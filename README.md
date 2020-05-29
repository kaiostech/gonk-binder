<!-- (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG KONG)
 * LIMITED or its affiliate company and may be registered in some jurisdictions.
 * All other trademarks are the property of their respective owners.
 -->

# Gonk AIDL binder README

This folder is created for those modules who need to communicate with
3rd party library via AIDL IPC interface.
You may create your own interfaces by following guide.

Please refer [1] to get more detail about AIDL and how it works.

# Guideline

1. Create your own aidl interface root folder: \<component>

2. You namespace/package shall be defined as below :
   b2g::\<component> / b2g.\<component>

   E.g.:
     using namesapce b2g::dummy;
     package b2g.dummy;

3. Library naming convention:
   binder_b2g_\<component>_interface

4. so file:
   We suggest to separate so file for every \<component>
   A Android.bp could defines multiple \<component> and generates .so accordingly.

   Android.bp example
```makefile
   // one package (service)
   aidl_interface {
       // the output will be put at
       // out/soong/.intermediates/path_to_aidl_root/binder_b2g_dummy_interface-*
       name: "binder_b2g_dummy_interface",
       local_include_dir: "binder",
       srcs: [
           "binder/b2g/dummy/IDummy.aidl",
           "binder/b2g/dummy/IDummyEventListener.aidl",
       ],
       api_dir: "aidl/dummy",
       versions: [
           "1",
       ],
   }

   // another package (service)
   aidl_interface {
       // out/soong/.intermediates/path_to_aidl_root/binder_b2gdummy_interface-*
       name: "binder_b2g_another_dummy_interface",
       local_include_dir: "binder",
       srcs: [
           "binder/b2g/dummy/IAnotherDummy.aidl",
           "binder/b2g/dummy/IAnotherDummyEventListener.aidl",
       ],
       api_dir: "aidl/another_dummy",
       versions: [
           "1",
       ],
   }
```

5. Build aidl interface and aquire generate files.
```
./build.sh binder_b2g_dummy_interface
```
or
```
make binder_b2g_dummy_interface
```
   Output will generate under _out/soong/.intermediates/path_to_aidl_root/binder_b2g_dummy_interface-*_

[1]: https://android.googlesource.com/platform/system/tools/aidl/+/brillo-m10-dev/docs/aidl-cpp.md

# API interface version control and management
Please refer [2] for the version management introduced by Android-10.
Suggest to design your interfaces and categorized them into \<component>s carefully to avoid rapid version increasing.

[2]: https://source.android.com/devices/architecture/aidl/stable-aidl#versioning-interfaces

# Conventions

## packages, namespace
- b2g.\<component>.*
- b2g::\<component>::*

## Getter functions
- If the getter result will be returned in blocking style, please method name starts with prefix `get`, ex:
```java
boolean getXXX();
```

- If the getter result will be return in non-block style and givein in callback, please method name starts with prefix `query`, ex:
```java
void queryXXX(QueryCallback cb);
```


## Callbacks
- If a callback is used to receive results requested by caller, please use interface name ended with `Callback`, ex:
```java
  void setAction(ActionResponseCallback cb);
```

## Listeners
- If a listener is used to receive unsolicited events from service, please use interface name ended with `Listener`, ex:
```java
void addNetworkStateChangeListener(NetworkStateChangeListener listener);

void removeNetworkStateChangeListener(NetworkStateChangeListener listener);
```

- If your service accept multiple listeners, please name your listener registration api with prefix `add` and `remove`, ex:
```java
void addNetworkStateChangeListener(NetworkStateChangeListener listener);

void removeNetworkStateChangeListener(NetworkStateChangeListener listener);
```

- If you service accept one listener only and the later one will override previous one, please name your listener registration api with prefix `set`, ex:
```java
// set(null) to unsubscribe.
void setNetworkStateChangeListener(NetworkStateChangeListener listener);
```

## Listeners API
- If a method is called after some operation is done, please name the api end with `Changed`.
- If you are unable to guarantee it use `Change`.
- For event indication, please named with prefix `on`.
```java
  void onXXXXChanged();
  void onXXXChange();
```

## String type
- If your string will be used between native and gecko, you probably use utf8 type with annotation `@utf8InCpp` since gcc default is utf8.
```
const @utf8InCpp String SOME_STRING = "my_constant";
```
- If you string will be passed to android system, ex: service name, you probably use utf16 directly to avoid utf8 to utf16 convertino.

Basically, Android's string default is utf16.
```
const String SOME_SERVICE = "my_service";
```

# Sample client/service
- [server-client](./server-client-sample): Please reference this folder for server-client sample code via b2g::connectivity::IConnectivity interfaces.
