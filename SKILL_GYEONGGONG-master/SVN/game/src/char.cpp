//Search

m_pkMuyeongEvent = NULL;

//Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL	
	m_pkGyeongGongEvent = NULL;
#endif

//Search

StopMuyeongEvent();

// Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
	StopGyeongGongEvent();
#endif
