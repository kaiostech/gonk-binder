package b2g.telephony.ims;
interface IImsRegistration {
  int getRegistrationTechnology();
  oneway void addListener(b2g.telephony.ims.IImsRegistrationListener listener);
  oneway void removeListener(b2g.telephony.ims.IImsRegistrationListener listener);
  const int RADIO_TECH_NONE = 0;
  const int RADIO_TECH_LTE = 1;
  const int RADIO_TECH_IWLAN = 2;
}
