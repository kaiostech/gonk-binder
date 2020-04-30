package b2g.connectivity;
interface IConnectivityEventListener {
  oneway void onActiveNetworkChanged(in b2g.connectivity.NetworkInfoParcel networkInfo);
  oneway void onNetworkChanged(in b2g.connectivity.NetworkInfoParcel networkInfo);
}
