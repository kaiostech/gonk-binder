package b2g.telephony;
interface ITelephony {
  int getSupportedRadioAccessFamily(int slotId);
  int getPhoneCount();
  const String SERVICE_NAME = "b2g_telephony_binder";
  const int NETWORK_TYPE_BITMASK_UNKNOWN = 1;
  const int NETWORK_TYPE_BITMASK_GPRS = 2;
  const int NETWORK_TYPE_BITMASK_EDGE = 4;
  const int NETWORK_TYPE_BITMASK_UMTS = 8;
  const int NETWORK_TYPE_BITMASK_CDMA = 16;
  const int NETWORK_TYPE_BITMASK_EVDO_0 = 32;
  const int NETWORK_TYPE_BITMASK_EVDO_A = 64;
  const int NETWORK_TYPE_BITMASK_1XRTT = 128;
  const int NETWORK_TYPE_BITMASK_HSDPA = 256;
  const int NETWORK_TYPE_BITMASK_HSUPA = 512;
  const int NETWORK_TYPE_BITMASK_HSPA = 1024;
  const int NETWORK_TYPE_BITMASK_IDEN = 2048;
  const int NETWORK_TYPE_BITMASK_EVDO_B = 4096;
  const int NETWORK_TYPE_BITMASK_LTE = 4096;
  const int NETWORK_TYPE_BITMASK_EHRPD = 16384;
  const int NETWORK_TYPE_BITMASK_HSPAP = 32768;
  const int NETWORK_TYPE_BITMASK_GSM = 65536;
  const int NETWORK_TYPE_BITMASK_TD_SCDMA = 131072;
  const int NETWORK_TYPE_BITMASK_IWLAN = 262144;
  const int NETWORK_TYPE_BITMASK_LTE_CA = 524288;
  const int NETWORK_TYPE_BITMASK_NR = 1048576;
}
