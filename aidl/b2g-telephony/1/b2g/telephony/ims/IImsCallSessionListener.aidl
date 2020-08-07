package b2g.telephony.ims;
interface IImsCallSessionListener {
  oneway void onCallSessionProgressing(in b2g.telephony.ims.ImsStreamMediaProfileParcelable mediaProfile);
  oneway void onCallSessionStarted(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionStartFailed(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionTerminated(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionHeld(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionHoldFailed(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionResumed(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionResumeFailed(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionHoldReceived(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionResumeReceived(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionUpdated(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  oneway void onCallSessionRttModifyRequestReceived(in b2g.telephony.ims.ImsCallProfileParcelable toProfile);
  oneway void onCallSessionRttModifyResponseReceived(in int status);
  oneway void onCallSessionRttMessageReceived(in @utf8InCpp String rttMessage);
  oneway void onCallSessionRttAudioIndicatorChanged(in b2g.telephony.ims.ImsStreamMediaProfileParcelable mediaProfile);
  oneway void onCallSessionSuppServiceReceived(in b2g.telephony.ims.ImsSuppServiceNotificationParcelable suppSrvNotification);
  oneway void onCallSessionTtyModeReceived(in int mode);
  oneway void onCallSessionMayHandover(int srcTech, int targetTech);
  oneway void onCallSessionHandover(int srcTech, int targetTech);
  oneway void onCallSessionHandoverFailed(int srcTech, int targetTech, in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionConferenceStateUpdated(in b2g.telephony.ims.ImsConferenceParticipantParcelable[] participants);
  oneway void onCallSessionRemoveParticipantsRequestDelivered();
  oneway void onCallSessionRemoveParticipantsRequestFailed(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
  oneway void onCallSessionTransferred();
  oneway void onCallSessionTransferFailed(in b2g.telephony.ims.ImsReasonInfoParcelable reasonInfo);
}
