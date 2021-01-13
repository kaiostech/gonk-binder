package b2g.remotesimunlock;
interface IRSURequestListener {
  oneway void onResponse(in int requestType, in int token, in int responseCode, in int data1, in int data2, in long data3, in byte[] responseData);
  const int RSU_RESP_SUCCESS = 0;
  const int RSU_RESP_FAILURE = 1;
  const int RSU_RESP_TIMER_ERROR = 2;
}
