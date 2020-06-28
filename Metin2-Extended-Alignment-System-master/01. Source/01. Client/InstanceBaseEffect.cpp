//1.1) Search for:
void CInstanceBase::RegisterTitleName(int iIndex, const char * c_szTitleName)
{
	g_TitleNameMap.insert(make_pair(iIndex, c_szTitleName));
}
//1.2) Replace with:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
void CInstanceBase::RegisterTitleName(const int iIndex, const char * c_szTitleNameF, const char * c_szTitleNameM)
{
	const std::vector<const std::string> vecTitleName{c_szTitleNameF, c_szTitleNameM};
	g_TitleNameMap.insert(make_pair(iIndex, vecTitleName));
}
#else
void CInstanceBase::RegisterTitleName(int iIndex, const char * c_szTitleName)
{
	g_TitleNameMap.insert(make_pair(iIndex, c_szTitleName));
}
#endif

//2.1) Search for:
std::map<int, std::string> g_TitleNameMap;
//2.2) Replace with:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
std::map<const BYTE, const std::vector<const std::string>> g_TitleNameMap;
#else
std::map<int, std::string> g_TitleNameMap;
#endif

//3.1) Search for:
		std::map<int, std::string>::iterator itor = g_TitleNameMap.find(iAlignmentGrade);
		if (g_TitleNameMap.end() != itor)
		{
			const std::string & c_rstrTitleName = itor->second;
			CPythonTextTail::Instance().AttachTitle(GetVirtualID(), c_rstrTitleName.c_str(), GetTitleColor());
		}
//3.2) Replace with:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
		std::map<const BYTE, const std::vector<const std::string>>::const_iterator itor = g_TitleNameMap.find(iAlignmentGrade);
#else
		std::map<int, std::string>::iterator itor = g_TitleNameMap.find(iAlignmentGrade);
#endif
		if (g_TitleNameMap.end() != itor)
		{
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
			const BYTE bRace = GetJob();
			const BYTE bSex = RaceToSex(bRace);
			const std::string & c_rstrTitleName = itor->second.at(bSex);
#else
			const std::string & c_rstrTitleName = itor->second;
#endif
			CPythonTextTail::Instance().AttachTitle(GetVirtualID(), c_rstrTitleName.c_str(), GetTitleColor());
		}