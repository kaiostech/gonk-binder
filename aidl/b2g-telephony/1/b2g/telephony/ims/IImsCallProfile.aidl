package b2g.telephony.ims;
interface IImsCallProfile {
  const int SERVICE_TYPE_NONE = 0;
  const int SERVICE_TYPE_NORMAL = 1;
  const int SERVICE_TYPE_EMERGENCY = 2;
  const int CALL_TYPE_VOICE_N_VIDEO = 1;
  const int CALL_TYPE_VOICE = 2;
  const int CALL_TYPE_VIDEO_N_VOICE = 3;
  const int CALL_TYPE_VT = 4;
  const int CALL_TYPE_VT_TX = 5;
  const int CALL_TYPE_VT_RX = 6;
  const int CALL_TYPE_VT_NODIR = 7;
  const int CALL_TYPE_VS = 8;
  const int CALL_TYPE_VS_TX = 9;
  const int CALL_TYPE_VS_RX = 10;
  const int OIR_DEFAULT = 0;
  const int OIR_PRESENTATION_RESTRICTED = 1;
  const int OIR_PRESENTATION_NOT_RESTRICTED = 2;
  const int OIR_PRESENTATION_UNKNOWN = 3;
  const int OIR_PRESENTATION_PAYPHONE = 4;
  const int DIALSTRING_NORMAL = 0;
  const int VERIFICATION_STATUS_NOT_VERIFIED = 0;
  const int VERIFICATION_STATUS_PASSED = 1;
  const int VERIFICATION_STATUS_FAILED = 2;
  const int CALL_RESTRICT_CAUSE_NONE = 0;
  const int CALL_RESTRICT_CAUSE_RAT = 1;
  const int CALL_RESTRICT_CAUSE_DISABLED = 2;
  const int CALL_RESTRICT_CAUSE_HD = 3;
}
