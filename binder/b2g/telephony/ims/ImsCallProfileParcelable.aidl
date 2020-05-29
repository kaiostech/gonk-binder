/*
 * Copyright (c) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.telephony.ims;

import b2g.telephony.ims.IImsCallProfile;
import b2g.telephony.ims.ImsStreamMediaProfileParcelable;

parcelable ImsCallProfileParcelable {
  /**
   * The service type this call associated with.
   * Possible values: IImsCallProfile#SERVICE_TYPE_*.
   */
  int serviceType;

  /**
   * The call type this call associated with.
   * Possible values: IImsCallProfile#CALL_TYPE_*.
   */
  int callType;

  /**
   * The media profile this call associated with.
   */
  ImsStreamMediaProfileParcelable mediaProfile;

  /**
   * String properties for IMS call.
   */
  /**
   * Originating identity (number), MT only;
   * (OI)
   */
  @utf8InCpp String originatingIdentity;

  /**
   * Calling name.
   * (CNA).
   */
  @utf8InCpp String callingName;

  /**
   * int properties for IMS call.
   */
  /**
   * Rule for originating identity (number) presentation, MO/MT.
   * Possible values: IImsCallProfile#OIR_*.
   */
  int oir;

  /**
   * Rule for calling name presentation.
   * Possible values: IImsCallProfile#OIR_*.
   */
  int cnap;

  /**
   * To identify the IMS call type, MO
   * Possible values: IImsCallProfile#DIALSTRING_*.
   */
  int dialString;
}