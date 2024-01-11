package b2g.telephony.ims;
interface IImsRegistrationListener {
  oneway void onRegistered(int imsRadioTech);
  oneway void onRegistering(int imsRadioTech);
  oneway void onDeregistered(int reasonInfo);
  oneway void onTechnologyChangeFailed(int imsRadioTech, in b2g.telephony.ims.ImsReasonInfoParcelable reason);
}
