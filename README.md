/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG KONG)
 * LIMITED or its affiliate company and may be registered in some jurisdictions.
 * All other trademarks are the property of their respective owners.
 */

[ Gonk AIDL binder README ]
=====================

This folder is created for those modules who need to communicate with
3rd party library via AIDL IPC interface.
You may create your own interfaces by following guide.

Please refer [1] to get more detail about AIDL and how it works.

=====================

[ Guideline ]
=====================

1. Create your own aidl interface root folder.
   <component>

2. You namespace/package shall be defined as below :
   b2g::<component> / b2g.<component>

   E.g.:
     using namesapce b2g::dummy;
     package b2g.dummy;

3. Library naming convention:
   binder_b2g_<component>_interface

4. so file:
   We suggest to separate so file for every <component>
   A Android.bp could define multiple <component> and generates .so accordingly.

   Android.bp example
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
       api_dir: "aidl/",
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
       api_dir: "aidl/",
       versions: [
           "1",
       ],
   }

5. Build aidl interface and aquire generate files.
   ./build.sh binder_b2g_dummy_interface or
   make binder_b2g_dummy_interface
   Output will generate under out/soong/.intermediates/path_to_aidl_root/binder_b2g_dummy_interface-*

[1]: https://android.googlesource.com/platform/system/tools/aidl/+/brillo-m10-dev/docs/aidl-cpp.md

=====================

[ API interface version control and management ]
=====================
Please refer [1] for the version management introduced by Android-10.
Suggest to design your interfaces and categorized them into <component>s carefully to avoid rapid version increasing.

[1]: https://source.android.com/devices/architecture/aidl/stable-aidl#defining-an-aidl-interface

[ Conventions ]
=====================
packages, namespace
  b2g.<component>.*
  b2g::<component>::*

Getter functions
  If the getter result will be returned in blocking style, please method name starts with prefix 'get', ex:
  [rtype] getXXX();

  If the getter result will be return in non-block style and givein in callback, please method name starts with prefix 'query', ex:
  void queryXXX(cb);


Callbacks:
  If a callback is used to receive results requested by caller, please use interface name ended with 'Callback', ex:
  void setAction(ActionResponseCallback cb);

  if a callback is used to receive unsolicited events from service, please use interface name ended with 'Listener', ex:
  void addNetworkStateChangeListener(NetworkStateChangeListener listener);
  void removeNetworkStateChangeListener(NetworkStateChangeListener listener);

[ Sample client/service ]
=====================
