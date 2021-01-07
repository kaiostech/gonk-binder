package b2g.telephony.ims;
interface IImsServiceManager {
  oneway void turnOnIms(int slotId, boolean on);
  b2g.telephony.ims.IImsRegistration getRegistration(int slotId);
  b2g.telephony.ims.IImsConfig getConfig(int slotId);
  b2g.telephony.ims.IImsMMTelFeature createMmTelFeature(int slotId, in b2g.telephony.ims.IImsFeatureStatusListener listener);
  oneway void setDeathNotifier(in b2g.telephony.IDeathNotifier aNotifier);
  b2g.telephony.ims.IImsEcbm getEcbm(int slotId);
  const String IMS_SERVICE_MANAGER = "imsservicemanager";
}
