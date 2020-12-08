package b2g.remotesimunlock;
interface IRSUService {
  oneway void setRSUListener(in b2g.remotesimunlock.IRSURequestListener listener);
  oneway void updateBlob(in int token, in byte[] data);
  oneway void querySharedKey(in int token);
  oneway void generateHMAC(in int token, in byte[] data);
  oneway void queryBlobVersion(in int token);
  oneway void querySimlockStatusCode(in int token);
  oneway void generateRequestBlob(in int token);
  oneway void setUnlockTimer(in int token, in int requestType);
  const String RSU_SERVICE_MANAGER = "rsuservice";
  const int START_UNLOCK_TIMER = 1;
  const int STOP_UNLOCK_TIMER = 2;
}
