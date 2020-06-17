package b2g.telephony.ims;
parcelable ImsCallProfileParcelable {
  int serviceType;
  int callType;
  int restrictCause;
  b2g.telephony.ims.ImsStreamMediaProfileParcelable mediaProfile;
  @utf8InCpp String originatingIdentity;
  @utf8InCpp String callingName;
  int oir;
  int cnap;
  int dialString;
  boolean canMarkUnwantedCall;
  int callNumberVerificationStatus;
}
