/* (c) 2020 KAI OS TECHNOLOGIES (HONG KONG) LIMITED All rights reserved. This
 * file or any portion thereof may not be reproduced or used in any manner
 * whatsoever without the express written permission of KAI OS TECHNOLOGIES
 * (HONG KONG) LIMITED. KaiOS is the trademark of KAI OS TECHNOLOGIES (HONG
 * KONG) LIMITED or its affiliate company and may be registered in some
 * jurisdictions. All other trademarks are the property of their respective
 * owners.
 */

package b2g.telephony.ims;

import b2g.telephony.ims.IImsCallSession;
import b2g.telephony.ims.ImsCallProfileParcelable;
import b2g.telephony.ims.ImsReasonInfoParcelable;

/**
 *
 */
oneway interface IImsMMTelListener {
  /**
   * Called whenever there is a new incoming call.
   *
   * @param session call session object represents the new incoming call.
   * @param isUssd (not supported) if this flag is true, it indicates this incoming call is for ussd.
   * @param isUnknown if this flag is true, it indicates this call is marked as an unknown
   *        dialing call instead of an incoming call. It is happend in case like sending dial command
   *        (AT command) to modem to initial a outgoing call without UI/Telephony framework involved.
   */
  void onIncomingCall(IImsCallSession session, boolean isUssd, boolean isUnknown);

  /**
   * Notifed when Voice Message count change.
   * @param count the new voice message count.
   */
  void onVoiceMessageCountUpdate(int count);

  /*
   * Conference call apis.
   * These event should go through IImsCallSessionListener, but it looks like aidl-cpp doesn't allow
   * cyclic import, like A import B and B import A.
   * As a workaround, we import aidls in tree style.
   */
  /**
   * Notifies when call session merge started.
   *
   * @param newSession new call session after conference.
   * @param callProfile call profile associated with this call session.
   */
  void onCallSessionMergeStarted(in IImsCallSession newSession, in ImsCallProfileParcelable profile);

  /**
   * Notifies when call session merge complete.
   *
   * @param newSession new conference call session after conference.
   */
  void onCallSessionMergeComplete(in IImsCallSession newSession);

  /**
   * Notifies when call session merge fails.
   *
   * @param session the host session who request merge.
   * @param reasonInfo failure reason.
   */
  void onCallSessionMergeFailed(in IImsCallSession hostSession, in ImsReasonInfoParcelable reason);

  /**
   * Notifies when call is rejected by lower level automatically, ex: during consultative transfer session.
   * @param profile call profile associated with rejected call.
   * @param reason the reject reason code.
   *        For Consultative transfer, the reject reason should be IImsReasonInfo#CODE_REJECT_ONGOING_CALL_TRANSFER.
   */
  void onRejectedCall(in ImsCallProfileParcelable profile, in ImsReasonInfoParcelable reason);
}