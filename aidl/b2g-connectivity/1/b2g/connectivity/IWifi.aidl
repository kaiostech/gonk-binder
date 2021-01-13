package b2g.connectivity;
interface IWifi {
  int getWifiState();
  void addWifiStateListener(b2g.connectivity.IWifiStateListener listener);
  void removeWifiStateListener(b2g.connectivity.IWifiStateListener listener);
  const int WIFI_STATE_UNKNOWN = -1;
  const int WIFI_STATE_ENABLING = 1;
  const int WIFI_STATE_ENABLED = 2;
  const int WIFI_STATE_DISABLING = 3;
  const int WIFI_STATE_DISABLED = 4;
  const String SERVICE_NAME = "b2g_connectivity_wifi_binder";
}

