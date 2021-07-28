<!-- (c) 2021 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG KONG)
 * LIMITED or its affiliate company and may be registered in some jurisdictions.
 * All other trademarks are the property of their respective owners.
 -->

# KaiOS AIDL STUB LIB README
This folder provide an aidl stub library to ensure we won't cause build break
during update aidl code base without upgrade aidl version in development stage.
.

## Why we need stub library.
Since gonk-binder/gonk-q/gecko are locate at different branch, once you've
done your aidl lib & implementation, you won't be able to avoid build break issues
no matter in CI or real build if you want to add a new API in original aidl base
(since implementation will only build pass after provide override all necessary
virtual function which match with latest aidl).

So we create a stub library in this folder, stub library will create an
`InheritClass` based on `OriginalClass` and override all needed virtual functions.
For those services which implement by AIDL could inherit `InheritClass` instead of
`OriginalClass`, then they may skip to define some virtual functions to avoid
build break which cause by merge process.

## Examples.
Please refer Connectivity as examples.
Its implemetation is locate at `gecko/koost/connectivity/ConnectivityBinderService.cpp`
and it was inherit by `b2g_stub::connectivity::BaseConnectivity`
instead of `b2g::connectivity::BnConnectivity`.
```
class ConnectivityBinderService
    : public android::BinderService<ConnectivityBinderService>,
      public b2g_stub::connectivity::BaseConnectivity,
      public nsIObserver,
      public nsIConnectivityBinderService {
```

If `ConnectivityBinderService.cpp` still inherit by original aidl class
`b2g::connectivity::BnConnectivity`, we will get a build error once we want to introduce
a new function in `IConnectivity.aidl` due to we didn't define the override virtual
function after inherit `BnConnectivity` update intime (obviously we can't update both branch &
gonk-q at same time in CI/MR).

# Conventions in stub

## namespace
- OriginalClass: `b2g::<component>::*`
- InheritClass: `b2g_stub::<component>::*`

## path, override functions
1. Create header file in path `include/b2g_stub/<component>`.

2. Create inherit class in path `\<component>` directly.

3. Inherit class name `Base\<component>`.

4. override functions as below :
```
Status BaseComponent::newAPI(bool* _aidl_return) {
  return Status::fromExceptionCode(Status::Exception::EX_UNSUPPORTED_OPERATION);
}
```
