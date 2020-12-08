package b2g.remotesimunlock;
interface IRSURequestListener {
  oneway void onUpdateBlob(in int token, in int responseCode, in byte[] responseData);
  oneway void onQuerySharedKey(in int token, in int responseCode, in byte[] encryptedKey);
  oneway void onGenerateHMAC(in int token, in int responseCode, in byte[] hmac);
  oneway void onQueryVersion(in int token, in int responseCode, in int majorVersion, in int minorVersion);
  oneway void onQuerySimlockStatusCode(in int token, in int responseCode, in int lockStatusCode, in long unlockTime);
  oneway void onGenerateRequestBlob(in int token, in int responseCode, in byte[] requestData);
  oneway void onUnlockTimer(in int token, in int responseCode, in int timerValue);
  const int RSU_RESP_SUCCESS = 0;
  const int RSU_RESP_FAILURE = 1;
  const int RSU_RESP_TIMER_EXPIRED = 2;
}
