package b2g.telephony.data;
interface IDataCall {
  void setupDataCallByType(int sreviceId, int networkType);
  void deactivateDataCallByType(int sreviceId, int networkType);
  int getDefaultSlotId();
  oneway void addEventListener(b2g.telephony.data.IDataCallEventListener listener);
  oneway void removeEventListener(b2g.telephony.data.IDataCallEventListener listener);
  const String SERVICE_NAME = "b2g_datacall_binder";
}
