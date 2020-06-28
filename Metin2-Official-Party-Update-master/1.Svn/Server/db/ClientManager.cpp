//Find
void CClientManager::SendPartyOnSetup(CPeer* pkPeer)
{
	....
	....
}

///Change
void CClientManager::SendPartyOnSetup(CPeer* pkPeer)
{
#ifdef BL_PARTY_UPDATE
	for (auto channels : {1,2,3,4,99}) {
		TPartyMap & pm = m_map_pkChannelParty[channels];

		for (itertype(pm) it_party = pm.begin(); it_party != pm.end(); ++it_party) {
			sys_log(0, "PARTY SendPartyOnSetup Party [%u]", it_party->first);
			pkPeer->EncodeHeader(HEADER_DG_PARTY_CREATE, 0, sizeof(TPacketPartyCreate));
			pkPeer->Encode(&it_party->first, sizeof(DWORD));
			for (itertype(it_party->second) it_member = it_party->second.begin(); it_member != it_party->second.end(); ++it_member) {
				sys_log(0, "PARTY SendPartyOnSetup Party [%u] Member [%u]", it_party->first, it_member->first);
				pkPeer->EncodeHeader(HEADER_DG_PARTY_ADD, 0, sizeof(TPacketPartyAdd));
				pkPeer->Encode(&it_party->first, sizeof(DWORD));
				pkPeer->Encode(&it_member->first, sizeof(DWORD));
				pkPeer->Encode(&it_member->second.bRole, sizeof(BYTE));

				pkPeer->EncodeHeader(HEADER_DG_PARTY_SET_MEMBER_LEVEL, 0, sizeof(TPacketPartySetMemberLevel));
				pkPeer->Encode(&it_party->first, sizeof(DWORD));
				pkPeer->Encode(&it_member->first, sizeof(DWORD));
				pkPeer->Encode(&it_member->second.bLevel, sizeof(BYTE));
			}
		}
	}
#else
	TPartyMap & pm = m_map_pkChannelParty[pkPeer->GetChannel()];

	for (itertype(pm) it_party = pm.begin(); it_party != pm.end(); ++it_party)
	{
		sys_log(0, "PARTY SendPartyOnSetup Party [%u]", it_party->first);
		pkPeer->EncodeHeader(HEADER_DG_PARTY_CREATE, 0, sizeof(TPacketPartyCreate));
		pkPeer->Encode(&it_party->first, sizeof(DWORD));

		for (itertype(it_party->second) it_member = it_party->second.begin(); it_member != it_party->second.end(); ++it_member)
		{
			sys_log(0, "PARTY SendPartyOnSetup Party [%u] Member [%u]", it_party->first, it_member->first);
			pkPeer->EncodeHeader(HEADER_DG_PARTY_ADD, 0, sizeof(TPacketPartyAdd));
			pkPeer->Encode(&it_party->first, sizeof(DWORD));
			pkPeer->Encode(&it_member->first, sizeof(DWORD));
			pkPeer->Encode(&it_member->second.bRole, sizeof(BYTE));

			pkPeer->EncodeHeader(HEADER_DG_PARTY_SET_MEMBER_LEVEL, 0, sizeof(TPacketPartySetMemberLevel));
			pkPeer->Encode(&it_party->first, sizeof(DWORD));
			pkPeer->Encode(&it_member->first, sizeof(DWORD));
			pkPeer->Encode(&it_member->second.bLevel, sizeof(BYTE));
		}
	}
#endif
}