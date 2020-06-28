//Find
		typedef std::string keyT;

///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		typedef std::string keyBL;
		#endif
		
//Find
		void	RemoveFromList(keyA account, keyA companion);

///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		void	__AddToBlockList(keyA account, keyA companion);
		void	AddToBlockList(keyA account, keyA companion);
		bool	CheckMessengerList(std::string ch, std::string tch, BYTE type);
		void	__RemoveFromBlockList(keyA account, keyA companion);
		void	RemoveFromBlockList(keyA account, keyA companion);
		void	RemoveAllBlockList(keyA account);
		#endif
		
//Find
		void	LoadList(SQLMsg * pmsg);

///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		void	SendBlockLogin(keyA account, keyA companion);
		void	SendBlockLogout(keyA account, keyA companion);
		void	LoadBlockList(SQLMsg * pmsg);
		void	SendBlockList(keyA account);
		#endif
		
//Find
		std::set<DWORD>			m_set_requestToAdd;
		
///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		std::map<keyT, std::set<keyT> >	m_BlockRelation;
		std::map<keyT, std::set<keyT> >	m_InverseBlockRelation;
		std::set<DWORD>			m_set_requestToBlockAdd;
		#endif