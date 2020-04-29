package b2g.telephony.ims;
interface IImsCapabilityCallback {
  oneway void onChangeCapabilityResponse(int capability, int radioTech, int status);
}
