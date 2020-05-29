package b2g.telephony.ims;
interface IImsMMTelFeature {
  int getFeatureStatus();
  oneway void changeCapabilities(in b2g.telephony.ims.CapabilityChangeRequestParcelable request, b2g.telephony.ims.IImsCapabilityCallback callback);
  boolean getCapability(int capability, int radioTech);
  oneway void addCapabilityListener(b2g.telephony.ims.IImsCapabilityListener listener);
  oneway void removeCapabilityListener(b2g.telephony.ims.IImsCapabilityListener listener);
  b2g.telephony.ims.IImsUt getUtInterface();
  oneway void setListener(b2g.telephony.ims.IImsMMTelListener listener);
  b2g.telephony.ims.IImsCallSession createCallSession(in b2g.telephony.ims.ImsCallProfileParcelable profile);
  const int STATE_UNAVAILABLE = 0;
  const int STATE_INITIALIZING = 1;
  const int STATE_READY = 2;
  const int CAPABILITY_TYPE_VOICE = 1;
  const int CAPABILITY_TYPE_VIDEO = 2;
  const int CAPABILITY_TYPE_UT = 4;
  const int CAPABILITY_TYPE_SMS = 8;
}
