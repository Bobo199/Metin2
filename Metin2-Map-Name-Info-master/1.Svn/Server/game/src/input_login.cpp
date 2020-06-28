///Add
const std::map<int, const char*> _SpMapNames
{
	{7, "Example"},
	{41, "Mavi Bayrak-1"}
};
static void __SendMapNameInfo(LPCHARACTER ch)
{
	if (!ch /*|| !ch->IsGM()*/)	return;
	if (_SpMapNames.find(ch->GetMapIndex()) != _SpMapNames.end())
		ch->ChatPacket(CHAT_TYPE_INFO, "Map Name: %s", _SpMapNames.find(ch->GetMapIndex())->second);
	else {
		const auto pRegionInfo = SECTREE_MANAGER::instance().GetMapRegion(ch->GetMapIndex());
		if (pRegionInfo)
			ch->ChatPacket(CHAT_TYPE_INFO, "Map Name: %s", pRegionInfo->strMapName.c_str());
		else
			ch->ChatPacket(CHAT_TYPE_INFO, "Unknown Map Name: %d", ch->GetMapIndex());
	}
}

//Find
	_send_bonus_info(ch);
	
///Add
	__SendMapNameInfo(ch);