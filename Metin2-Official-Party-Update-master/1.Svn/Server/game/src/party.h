//Find
		typedef struct SMember
		{
			....
			....
		}

///Change
		typedef struct SMember
		{
			LPCHARACTER	pCharacter;
			bool	bNear;
			BYTE	bRole;
			BYTE	bLevel;
			std::string strName;
			#ifdef BL_PARTY_UPDATE
			BYTE 	channel;
			DWORD 	mapidx;
			#endif
		} TMember;
		
//Find
		void		P2PLogin(DWORD pid, const char* name);
		
///Change
	#ifdef BL_PARTY_UPDATE
		void		P2PLogin(DWORD pid, const char* name, BYTE channel, DWORD mapidx);
	#else
		void		P2PLogin(DWORD pid, const char* name);
	#endif
		
//Find
		void		UpdateOnlineState(DWORD dwPID, const char* name);
		
///Change
	#ifdef BL_PARTY_UPDATE
		void		UpdateOnlineState(DWORD dwPID, const char* name, BYTE channel, DWORD mapidx);
	#else
		void		UpdateOnlineState(DWORD dwPID, const char* name);
	#endif