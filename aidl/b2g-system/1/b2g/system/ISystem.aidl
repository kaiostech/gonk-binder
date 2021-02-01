package b2g.system;
interface ISystem {
  boolean getScreenState();
  oneway void addEventListener(b2g.system.ISystemEventListener listener);
  oneway void removeEventListener(b2g.system.ISystemEventListener listener);
  const String SERVICE_NAME = "b2g_system_binder";
}
