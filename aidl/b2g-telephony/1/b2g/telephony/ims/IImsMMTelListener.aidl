package b2g.telephony.ims;
interface IImsMMTelListener {
  oneway void onIncomingCall(b2g.telephony.ims.IImsCallSession session);
  oneway void onVoiceMessageCountUpdate(int count);
  oneway void onCallSessionMergeStarted(in b2g.telephony.ims.IImsCallSession newSession, in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionMergeComplete(in b2g.telephony.ims.IImsCallSession newSession);
  oneway void onCallSessionMergeFailed(in b2g.telephony.ims.IImsCallSession session, in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
}
