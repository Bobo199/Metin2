//Find
    		const CMob *	Get(const char * c_pszName, bool bIsAbbrev);
///Add
#ifdef RENEWAL_BOOK_NAME
		std::string GetMobName(DWORD dwVnum) {
			auto it = m_map_pkMobByVnum.find(dwVnum);
			return it == m_map_pkMobByVnum.end() ? "" : it->second->m_table.szLocaleName;
		}
#endif
