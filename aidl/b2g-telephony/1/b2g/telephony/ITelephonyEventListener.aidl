package b2g.telephony;
interface ITelephonyEventListener {
  oneway void onVoiceRegStateOrRatChanged(int slotId);
  oneway void onDataRegStateOrRatChanged(int slotId);
}
