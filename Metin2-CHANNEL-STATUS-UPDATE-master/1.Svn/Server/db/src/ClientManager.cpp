//Find
void CClientManager::UpdateChannelStatus(TChannelStatus* pData)
{
	...
	...
}

void CClientManager::RequestChannelStatus(CPeer* peer, DWORD dwHandle)
{
	...
	...
}

///Change
void CClientManager::UpdateChannelStatus(TChannelStatus* pData)
{
	TChannelStatusMap::iterator it = m_mChannelStatus.find(pData->nPort);
#if defined(__CHANNEL_STATUS_UPDATE__)
	if (it != m_mChannelStatus.end()) {
		it->second.first = pData->bStatus;
		it->second.second = pData->player_count;
	}
	else
		m_mChannelStatus.emplace(pData->nPort, std::make_pair(pData->bStatus, pData->player_count));
#else
	if (it != m_mChannelStatus.end()) {
		it->second = pData->bStatus;
	}
	else {
		m_mChannelStatus.insert(TChannelStatusMap::value_type(pData->nPort, pData->bStatus));
	}
#endif
}

void CClientManager::RequestChannelStatus(CPeer* peer, DWORD dwHandle)
{
	const int nSize = m_mChannelStatus.size();
	peer->EncodeHeader(HEADER_DG_RESPOND_CHANNELSTATUS, dwHandle, sizeof(TChannelStatus)*nSize+sizeof(int));
	peer->Encode(&nSize, sizeof(int));
#if defined(__CHANNEL_STATUS_UPDATE__)
	for (const auto& v : m_mChannelStatus) {
		peer->Encode(&v.first, sizeof(decltype(v.first)));
		peer->Encode(&v.second.first, sizeof(decltype(v.second.first)));
		peer->Encode(&v.second.second, sizeof(decltype(v.second.second)));
	}
#else
	for (TChannelStatusMap::iterator it = m_mChannelStatus.begin(); it != m_mChannelStatus.end(); it++) {
		peer->Encode(&it->first, sizeof(short));
		peer->Encode(&it->second, sizeof(BYTE));
	}
#endif
}
	