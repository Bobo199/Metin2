//1.1) Search for:
	if (!SetRace(c_rkCreateData.m_dwRace))
		return false;
//1.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	if (IsPC())
		SetJob(c_rkCreateData.m_bJob);
#endif

//2.1) Search for:
	m_dwRace = 0;
//2.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	m_bJob = 0;
#endif