//1.1 Search for:
	m_v2PickedInstProjPos = D3DXVECTOR2(0.0f, 0.0f);
//1.1 Add after:
#if defined(ENABLE_TAB_NEXT_TARGET)
	ResetTabNextTargetVectorIndex();
#endif

//1.2 Search for:
void CPythonCharacterManager::SelectInstance(DWORD VirtualID)
{
	TCharacterInstanceMap::iterator itor = m_kAliveInstMap.find(VirtualID);

	if (m_kAliveInstMap.end() == itor)
	{
		Tracef("SelectCharacterInstance: no vid by %d\n", VirtualID);
		return;
	}

	m_pkInstBind = itor->second;
}
//1.2 Add after:
#if defined(ENABLE_TAB_NEXT_TARGET)
CInstanceBase * CPythonCharacterManager::GetTabNextTargetPointer(CInstanceBase * pkInstMain)
{
	if (!pkInstMain)
	{
		ResetTabNextTargetVectorIndex();
		return NULL;
	}
	
	struct FCharacterManagerInstanceTarget
	{
		CInstanceBase * pkInstMain;
		FCharacterManagerInstanceTarget(CInstanceBase * pInstance) : pkInstMain(pInstance) {}

		inline void operator () (const std::pair<DWORD, CInstanceBase *>& itor)
		{
			CInstanceBase * pkInstTarget = itor.second;
			if (!pkInstTarget || pkInstTarget == pkInstMain || !pkInstTarget->IsEnemy())
				return;

			const float fRadiusDistance = pkInstMain->GetDistance(pkInstTarget);
			if (fRadiusDistance < 1500.0f)
				m_vecTargetInstance.push_back(pkInstTarget);
		}

		std::vector<CInstanceBase *> m_vecTargetInstance;
	};

	FCharacterManagerInstanceTarget f(pkInstMain);
	f = std::for_each(m_kAliveInstMap.begin(), m_kAliveInstMap.end(), f);

	const size_t kTargetCount = f.m_vecTargetInstance.size();
	if (kTargetCount == 0)
	{
		ResetTabNextTargetVectorIndex();
		return NULL;
	}

	if (GetTabNextTargetVectorIndex() >= kTargetCount - 1)
		ResetTabNextTargetVectorIndex();

	return f.m_vecTargetInstance.at(++m_adwVectorIndexTabNextTarget);
}
#endif
