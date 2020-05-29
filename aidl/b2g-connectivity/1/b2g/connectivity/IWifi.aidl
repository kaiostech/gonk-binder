package b2g.connectivity;
interface IWifi {
  boolean getEnabledState();
  void addWifiStateListener(b2g.connectivity.IWifiStateListener listener);
  void removeWifiStateListener(b2g.connectivity.IWifiStateListener listener);
  const String SERVICE_NAME = "b2g_connectivity_wifi_binder";
}

