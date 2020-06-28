//Find in void CHARACTER::Initialize()
	m_bSendHorseLevel = 0;
	
///Add
#if defined(PC_KILL_SOUND_EFFECT)
	m_dwLastPCKillTime = time(0);
	b_PCKillStage = 0;
#endif