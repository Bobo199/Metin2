//1.1) Search in: void SNetworkActorData::__copy__(const SNetworkActorData& src)
	m_dwRace = src.m_dwRace;
//1.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	m_bJob = src.m_bJob;
#endif

//2.1) Search in: SNetworkActorData::SNetworkActorData()
	m_dwRace=0;
//2.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	m_bJob=0;
#endif

//3.1) Search in: CInstanceBase* CNetworkActorManager::__AppendCharacterManagerActor(SNetworkActorData& rkNetActorData)
	kCreateData.m_dwRace=rkNetActorData.m_dwRace;
//3.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	kCreateData.m_bJob=rkNetActorData.m_bJob;
#endif