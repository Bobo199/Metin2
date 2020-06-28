//Find
		typedef std::set<std::string> TFriendNameMap;
		
///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		typedef std::set<std::string> TBlockNameMap;
		#endif
		
//Find
			MESSENGER_GRUOP_INDEX_GUILD,
	
///Add
			#ifdef ENABLE_MESSENGER_BLOCK
			MESSENGER_GROUP_INDEX_BLOCK,
			#endif
			
//Find
		void OnFriendLogout(const char * c_szKey);
		
///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		void RemoveBlock(const char * c_szKey);
		void OnBlockLogin(const char * c_szKey);
		void OnBlockLogout(const char * c_szKey);
		BOOL IsBlockByKey(const char * c_szKey);
		BOOL IsBlockByName(const char * c_szName);
		#endif
		
//Find
		TFriendNameMap m_FriendNameMap;
		
///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		TBlockNameMap m_BlockNameMap;
		#endif