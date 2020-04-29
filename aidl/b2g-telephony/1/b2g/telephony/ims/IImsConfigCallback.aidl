package b2g.telephony.ims;
interface IImsConfigCallback {
  oneway void onQueryConfigInt(int item, int value);
  oneway void onSetConfigInt(int item, int value, int status);
}
