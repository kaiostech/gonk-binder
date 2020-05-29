package b2g.telephony.ims;
interface IImsCallSessionListener {
  oneway void onCallSessionProgressing(in b2g.telephony.ims.ImsStreamMediaProfileParcelable profile);
  oneway void onCallSessionStarted(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionStartFailed(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionTerminated(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionHeld(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionHoldFailed(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionResumed(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionResumeFailed(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionHoldReceived(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionResumeReceived(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void callSessionUpdated(in b2g.telephony.ims.ImsCallProfileParcelable profile);
}
