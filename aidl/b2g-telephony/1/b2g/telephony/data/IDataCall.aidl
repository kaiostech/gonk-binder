package b2g.telephony.data;
interface IDataCall {
  void setupDataCallByType(int sreviceId, int networkType);
  void deactivateDataCallByType(int sreviceId, int networkType);
  const String SERVICE_NAME = "b2g_datacall_binder";
}
