package b2g.connectivity;

interface ITetheringStatusListener {
  oneway void onTetheringStatusChanged(in b2g.connectivity.TetheringStatusParcel tetheringStatus);
}

