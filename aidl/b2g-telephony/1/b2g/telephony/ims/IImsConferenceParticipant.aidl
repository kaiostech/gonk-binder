package b2g.telephony.ims;
interface IImsConferenceParticipant {
  const int STATUS_PENDING = 0;
  const int STATUS_DIALING_OUT = 1;
  const int STATUS_DIALING_IN = 2;
  const int STATUS_ALERTING = 3;
  const int STATUS_ON_HOLD = 4;
  const int STATUS_CONNECTED = 5;
  const int STATUS_DISCONNECTING = 6;
  const int STATUS_DISCONNECTED = 7;
  const int STATUS_MUTED_VIA_FOCUS = 8;
  const int STATUS_CONNECT_FAIL = 9;
  const int STATUS_SEND_ONLY = 10;
  const int STATUS_SEND_RECV = 11;
}
