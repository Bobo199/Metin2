///Add
bool CPolymorphUtils::CheckMap(LPCHARACTER pChar)
{
	std::list<DWORD> maplist {113, 41}; // edit
	const auto it = std::find(maplist.begin(), maplist.end(), pChar->GetMapIndex());
	return it == maplist.end();
}