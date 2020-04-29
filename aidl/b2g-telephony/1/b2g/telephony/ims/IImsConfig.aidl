package b2g.telephony.ims;
interface IImsConfig {
  void queryConfigInt(int item, in b2g.telephony.ims.IImsConfigCallback callback);
  void setConfigInt(int item, int value, in b2g.telephony.ims.IImsConfigCallback callback);
  const int VOICE_OVER_WIFI_ROAMING_DISASBLED = 0;
  const int VOICE_OVER_WIFI_ROAMING_ENABLED = 1;
  const int VOICE_OVER_WIFI_ROAMING = 26;
  const int WIFI_MODE_WIFI_ONLY = 0;
  const int WIFI_MODE_CELLULAR_PREFERRED = 1;
  const int WIFI_MODE_WIFI_PREFERRED = 2;
  const int VOICE_OVER_WIFI_MODE = 27;
  const int VOICE_OVER_WIFI_DISABLED = 0;
  const int VOICE_OVER_WIFI_ENABLED = 1;
  const int VOICE_OVER_WIFI_SETTING_ENABLED = 28;
  const int OPERATION_STATUS_UNKNOWN = -1;
  const int OPERATION_STATUS_SUCCESS = 0;
  const int OPERATION_STATUS_FAILED = 1;
  const int OPERATION_STATUS_UNSUPPORTED_CAUSE_NONE = 2;
  const int OPERATION_STATUS_UNSUPPORTED_CAUSE_RAT = 3;
  const int OPERATION_STATUS_UNSUPPORTED_CAUSE_DISABLED = 4;
}
