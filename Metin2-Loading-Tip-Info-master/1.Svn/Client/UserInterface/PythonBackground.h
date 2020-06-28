//Find
	const char* GetWarpMapName();

///Add
#if defined(__LOADING_TIP__)
	void SetWarpMapInfo(long m) { l_WarpMapIndex = m; }
	long GetWarpMapIndex() const { return l_WarpMapIndex; }
#endif

//Find
	std::string m_strMapName;
	
///Add
#if defined(__LOADING_TIP__)
	long l_WarpMapIndex;
#endif