//1.1) Search in: bool CPythonNetworkStream::RecvCharacterAdditionalInfo()
		kNetActorData.m_dwMountVnum=chrInfoPacket.dwMountVnum;
//1.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
		kNetActorData.m_bJob=chrInfoPacket.bJob;
#endif