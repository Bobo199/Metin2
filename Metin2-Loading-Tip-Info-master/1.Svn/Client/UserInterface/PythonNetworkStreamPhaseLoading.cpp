//Find
bool CPythonNetworkStream::IsInsultIn(const char* c_szMsg)
{
	return m_kInsultChecker.IsInsultIn(c_szMsg, strlen(c_szMsg));
}

///Add
#if defined(__LOADING_TIP__)
bool CPythonNetworkStream::LoadTipVnum(const char* FileName)
{
	const VOID* pvData;
	CMappedFile kFile;
	if (!CEterPackManager::Instance().Get(kFile, FileName, &pvData))
		return false;

	m_TipVnum.clear();
	CMemoryTextFileLoader kTextFileLoader;
	kTextFileLoader.Bind(kFile.Size(), pvData);	
	CTokenVector kTokenVector;

	for (DWORD i = 0; i < kTextFileLoader.GetLineCount(); ++i)
		if (kTextFileLoader.SplitLineByTab(i, &kTokenVector))
			m_TipVnum.emplace(stoi(kTokenVector[0]), kTokenVector[1]);
	return true;
}
#endif