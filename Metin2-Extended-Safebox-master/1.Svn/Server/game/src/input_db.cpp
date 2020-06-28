//Find(2x) in void CInputDB::SafeboxLoad(LPDESC d, const char * c_pData)
		bSize = 3;
	
///Change(2x)
#if defined(__EXTENDED_SAFEBOX__)
		bSize = SAFEBOX_MAX_PAGE_COUNT;
#else
		bSize = 3;
#endif