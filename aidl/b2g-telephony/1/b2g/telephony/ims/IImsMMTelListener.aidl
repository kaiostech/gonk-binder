package b2g.telephony.ims;
interface IImsMMTelListener {
  oneway void onIncomingCall(b2g.telephony.ims.IImsCallSession session, boolean isUssd, boolean isUnknown);
  oneway void onVoiceMessageCountUpdate(int count);
  oneway void onCallSessionMergeStarted(in b2g.telephony.ims.IImsCallSession newSession, in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionMergeComplete(in b2g.telephony.ims.IImsCallSession newSession);
  oneway void onCallSessionMergeFailed(in b2g.telephony.ims.IImsCallSession hostSession, in b2g.telephony.ims.ImsReasonInfoParcelable reason);
  oneway void onRejectedCall(in b2g.telephony.ims.ImsCallProfileParcelable profile, in b2g.telephony.ims.ImsReasonInfoParcelable reason);
}
