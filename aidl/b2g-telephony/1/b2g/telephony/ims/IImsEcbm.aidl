package b2g.telephony.ims;
interface IImsEcbm {
  oneway void setListener(in b2g.telephony.ims.IImsEcbmListener listener);
  void exitEmergencyCallbackMode();
}
