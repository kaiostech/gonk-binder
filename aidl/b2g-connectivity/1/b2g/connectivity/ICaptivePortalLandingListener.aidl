package b2g.connectivity;

interface ICaptivePortalLandingListener {
  oneway void onCaptivePortalLandingChanged(in b2g.connectivity.CaptivePortalLandingParcel captivePortalLandingParcel);
}
