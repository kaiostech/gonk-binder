package b2g.telephony.ims;
interface IImsUtCallback {
  oneway void onCallForwardQueried(int id, in b2g.telephony.ims.ImsCallForwardInfoParcelable[] cfInfos);
  oneway void onUtConfigurationUpdated(int id);
  oneway void onUtConfigurationUpdateFailed(int id, in b2g.telephony.ims.ImsReasonInfoParcelable error);
  oneway void onCallBarringQueried(int id, in b2g.telephony.ims.ImsSsInfoParcelable cbInfo);
  oneway void onCallWaitingQueried(int id, in b2g.telephony.ims.ImsSsInfoParcelable cwInfo);
  oneway void utConfigurationQueryFailed(int id, in b2g.telephony.ims.ImsReasonInfoParcelable error);
  oneway void onClirQueried(int id, in b2g.telephony.ims.ImsClirResponseParcelable clirStatus);
}
