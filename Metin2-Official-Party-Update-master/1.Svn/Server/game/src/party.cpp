//Find
void CPartyManager::P2PLogin(DWORD pid, const char* name)
{
	....
	....
}

///Change
#ifdef BL_PARTY_UPDATE
void CPartyManager::P2PLogin(DWORD pid, const char* name, BYTE channel, DWORD mapidx)
#else
void CPartyManager::P2PLogin(DWORD pid, const char* name)
#endif
{
	TPartyMap::iterator it = m_map_pkParty.find(pid);

	if (it == m_map_pkParty.end())
		return;

#ifdef BL_PARTY_UPDATE
	it->second->UpdateOnlineState(pid, name, channel, mapidx);
#else	
	it->second->UpdateOnlineState(pid, name);
#endif
}

//Find
void CParty::P2PJoin(DWORD dwPID)
{
	....
	....
}

///Change
void CParty::P2PJoin(DWORD dwPID)
{
	TMemberMap::iterator it = m_memberMap.find(dwPID);

	if (it == m_memberMap.end())
	{
		TMember Member;

		Member.pCharacter	= NULL;
		Member.bNear		= false;

		if (m_memberMap.empty())
		{
			Member.bRole = PARTY_ROLE_LEADER;
			m_dwLeaderPID = dwPID;
		}
		else
			Member.bRole = PARTY_ROLE_NORMAL;

		if (m_bPCParty)
		{
			LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(dwPID);

			if (ch)
			{
				sys_log(0, "PARTY: Join %s pid %u leader %u", ch->GetName(), dwPID, m_dwLeaderPID);
				Member.strName = ch->GetName();

				if (Member.bRole == PARTY_ROLE_LEADER)
					m_iLeadership = ch->GetLeadershipSkillLevel();
				#ifdef BL_PARTY_UPDATE
				Member.mapidx = ch->GetMapIndex();
				Member.channel = g_bChannel;
				#endif
			}
			else
			{
				CCI * pcci = P2P_MANAGER::instance().FindByPID(dwPID);

				if (!pcci);
				else if (pcci->bChannel == g_bChannel) {
					Member.strName = pcci->szName;
					#ifdef BL_PARTY_UPDATE
					Member.mapidx = pcci->lMapIndex;
					Member.channel = pcci->bChannel;
					#endif
				}
				else
					sys_err("member is not in same channel PID: %u channel %d, this channel %d", dwPID, pcci->bChannel, g_bChannel);
			}
		}

		sys_log(2, "PARTY[%d] MemberCountChange %d -> %d", GetLeaderPID(), GetMemberCount(), GetMemberCount()+1);

		m_memberMap.insert(TMemberMap::value_type(dwPID, Member));

		if (m_memberMap.size() == 1)
			m_itNextOwner = m_memberMap.begin();

		if (m_bPCParty)
		{
			CPartyManager::instance().SetPartyMember(dwPID, this);
			SendPartyJoinOneToAll(dwPID);

			LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(dwPID);

			if (ch)
				SendParameter(ch);
		}
	}

	if (m_pkDungeon)
	{
		m_pkDungeon->QuitParty(this);
	}
}

//Find
void CParty::SendPartyJoinOneToAll(DWORD pid)
{
	....
	....
}

///Change
void CParty::SendPartyJoinOneToAll(DWORD pid)
{
	const TMember& r = m_memberMap[pid];

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.pid = pid;
	strlcpy(p.name, r.strName.c_str(), sizeof(p.name));
#ifdef BL_PARTY_UPDATE
	p.mapidx = r.mapidx;
	p.channel = r.channel;
#endif

	for (TMemberMap::iterator it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		#ifdef BL_PARTY_UPDATE
		CCI *pCCI = P2P_MANAGER::instance().Find(it->second.strName.c_str());
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		else if (pCCI)
			pCCI->pkDesc->Packet(&p, sizeof(p));
		#else	
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		#endif
	}
}

//Find
void CParty::SendPartyJoinAllToOne(LPCHARACTER ch)
{
	....
	....
}

///Change
#ifdef BL_PARTY_UPDATE
void CParty::SendPartyJoinAllToOne(LPCHARACTER ch)
{
	if (!ch->GetDesc())
		return;
	for (TMemberMap::iterator it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		CCI *pCCI = P2P_MANAGER::instance().Find(it->second.strName.c_str());
		if (it->second.pCharacter || pCCI)
			UpdateOnlineState(it->first, it->second.strName.c_str(), it->second.channel, it->second.mapidx);
		else
			UpdateOfflineState(it->first);
	}
}
#else
void CParty::SendPartyJoinAllToOne(LPCHARACTER ch)
{
	if (!ch->GetDesc())
		return;

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.name[CHARACTER_NAME_MAX_LEN] = '\0';

	for (TMemberMap::iterator it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		p.pid = it->first;
		strlcpy(p.name, it->second.strName.c_str(), sizeof(p.name));
		ch->GetDesc()->Packet(&p, sizeof(p));
	}
}	
#endif

//Find
void CParty::SendPartyUnlinkOneToAll(LPCHARACTER ch)
{
	....
	....
}

///Change
void CParty::SendPartyUnlinkOneToAll(LPCHARACTER ch)
{
	if (!ch->GetDesc())
		return;

	TMemberMap::iterator it;

	TPacketGCPartyLink p;
	p.header = HEADER_GC_PARTY_UNLINK;
	p.pid = ch->GetPlayerID();
	p.vid = (DWORD)ch->GetVID();
#ifdef BL_PARTY_UPDATE
	p.channel = 0;
	p.mapidx = 0;
#endif

	for (it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		#ifdef BL_PARTY_UPDATE
		CCI *pCCI = P2P_MANAGER::instance().Find(it->second.strName.c_str());
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		else if (pCCI)
			pCCI->pkDesc->Packet(&p, sizeof(p));
		#else
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		#endif
	}
}

//Find
void CParty::SendPartyLinkOneToAll(LPCHARACTER ch)
{
	....
	....
}

///Change
void CParty::SendPartyLinkOneToAll(LPCHARACTER ch)
{
	if (!ch->GetDesc())
		return;

	TMemberMap::iterator it;

	TPacketGCPartyLink p;
	p.header = HEADER_GC_PARTY_LINK;
	p.vid = ch->GetVID();
	p.pid = ch->GetPlayerID();
#ifdef BL_PARTY_UPDATE
	p.channel = g_bChannel;
	p.mapidx = ch->GetMapIndex();
#endif

	for (it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		#ifdef BL_PARTY_UPDATE
		CCI *pCCI = P2P_MANAGER::instance().Find(it->second.strName.c_str());
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		else if (pCCI)
			pCCI->pkDesc->Packet(&p, sizeof(p));
		#else
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		#endif
	}
}

//Find
void CParty::SendPartyLinkAllToOne(LPCHARACTER ch)
{
	....
	....
}

///Change
void CParty::SendPartyLinkAllToOne(LPCHARACTER ch)
{
	if (!ch->GetDesc())
		return;

	TMemberMap::iterator it;

	TPacketGCPartyLink p;
	p.header = HEADER_GC_PARTY_LINK;

	for (it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		if (it->second.pCharacter)
		{
			p.vid = it->second.pCharacter->GetVID();
			p.pid = it->second.pCharacter->GetPlayerID();
			#ifdef BL_PARTY_UPDATE
			p.channel = g_bChannel;
			p.mapidx = it->second.pCharacter->GetMapIndex();
			#endif
			ch->GetDesc()->Packet(&p, sizeof(p));
		}
	}
}

//Find
void CParty::UpdateOnlineState(DWORD dwPID, const char* name)
{
	....
	....
}

///Change
#ifdef BL_PARTY_UPDATE
void CParty::UpdateOnlineState(DWORD dwPID, const char* name, BYTE channel, DWORD mapidx)
#else
void CParty::UpdateOnlineState(DWORD dwPID, const char* name)
#endif
{
	TMember& r = m_memberMap[dwPID];

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.pid = dwPID;
	r.strName = name;
	strlcpy(p.name, name, sizeof(p.name));
#ifdef BL_PARTY_UPDATE	
	p.channel = channel;
	p.mapidx = mapidx;
#endif
	for (TMemberMap::iterator it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		#ifdef BL_PARTY_UPDATE
		CCI *pCCI = P2P_MANAGER::instance().Find(it->second.strName.c_str());
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		else if (pCCI)
			pCCI->pkDesc->Packet(&p, sizeof(p));
		#else	
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		#endif
	}
}

//Find
void CParty::UpdateOfflineState(DWORD dwPID)
{
	....
	....
}

///Change
void CParty::UpdateOfflineState(DWORD dwPID)
{
	//const TMember& r = m_memberMap[dwPID];

	TPacketGCPartyAdd p;
	p.header = HEADER_GC_PARTY_ADD;
	p.pid = dwPID;
	memset(p.name, 0, CHARACTER_NAME_MAX_LEN+1);
#ifdef BL_PARTY_UPDATE	
	p.channel = 0;
	p.mapidx = 0;
#endif
	for (TMemberMap::iterator it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		#ifdef BL_PARTY_UPDATE
		CCI *pCCI = P2P_MANAGER::instance().Find(it->second.strName.c_str());
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		else if (pCCI)
			pCCI->pkDesc->Packet(&p, sizeof(p));
		#else	
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		#endif
	}
}
