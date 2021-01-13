package b2g.remotesimunlock;
interface IRSUService {
  oneway void addRSUListener(in b2g.remotesimunlock.IRSURequestListener listener);
  oneway void removeRSUListener(in b2g.remotesimunlock.IRSURequestListener listener);
  oneway void rsuRequest(in int requestType, in int token, in byte[] data);
  oneway void rsuExtraRequest(in int requestType, in int token, in byte[] data);
  const String RSU_SERVICE_MANAGER = "rsuservice";
  const int RSU_TYPE_UPDATE_BLOB = 0;
  const int RSU_TYPE_QUERY_SHARED_KEY = 1;
  const int RSU_TYPE_GENERATE_HMAC = 2;
  const int RSU_TYPE_QUERY_BLOB_VERSION = 3;
  const int RSU_TYPE_QUERY_STATUS_CODE = 4;
  const int RSU_TYPE_GENERATE_REQUEST_BLOB = 5;
  const int RSU_TYPE_START_UNLOCK_TIMER = 6;
  const int RSU_TYPE_STOP_UNLOCK_TIMER = 7;
}
