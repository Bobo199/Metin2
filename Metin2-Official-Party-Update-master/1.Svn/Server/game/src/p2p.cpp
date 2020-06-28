//Find
	CPartyManager::instance().P2PLogin(pkCCI->dwPID, pkCCI->szName);
	
///Change
#ifdef BL_PARTY_UPDATE
	CPartyManager::instance().P2PLogin(pkCCI->dwPID, pkCCI->szName, pkCCI->bChannel, pkCCI->lMapIndex);
#else
	CPartyManager::instance().P2PLogin(pkCCI->dwPID, pkCCI->szName);
#endif