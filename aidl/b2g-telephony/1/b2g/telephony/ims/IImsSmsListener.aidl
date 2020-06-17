package b2g.telephony.ims;
interface IImsSmsListener {
  oneway void onSendSmsResult(int token, int messageRef, int status, int reason, int networkErrorCode);
  oneway void onSmsStatusReportReceived(int token, in @utf8InCpp String format, in byte[] pdu);
  oneway void onSmsReceived(int token, in @utf8InCpp String format, in byte[] pdu);
}
