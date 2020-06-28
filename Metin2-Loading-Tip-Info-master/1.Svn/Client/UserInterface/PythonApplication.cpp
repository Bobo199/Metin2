//Find
	if (!rkItemMgr.LoadItemList(szItemList))
	{
		TraceError("LoadLocaleData - LoadItemList(%s) Error", szItemList);
	}
	
///Add
#if defined(__LOADING_TIP__)
	char szTipVnum[256];
	snprintf(szTipVnum, sizeof(szTipVnum), "%s/loading_tip_vnum.txt", localePath);
	if (!rkNetStream.LoadTipVnum(szTipVnum)) {
		TraceError("LoadLocaleData - LoadTipVnum(%s) Error", szTipVnum);
		return false;
	}
#endif