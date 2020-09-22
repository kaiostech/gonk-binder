package b2g.connectivity;

parcelable NetworkInfoParcel {
  @utf8InCpp String name;
  int netId;
  int state;
  int type;
  int[] prefixLengths;
  @utf8InCpp String[] ips;
  @utf8InCpp String[] gateways;
  @utf8InCpp String[] dnses;
}
