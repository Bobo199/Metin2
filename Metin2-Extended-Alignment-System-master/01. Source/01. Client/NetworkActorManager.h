//1.1) Search in: struct SNetworkActorData
	DWORD	m_dwRace;
//1.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	BYTE	m_bJob;
#endif