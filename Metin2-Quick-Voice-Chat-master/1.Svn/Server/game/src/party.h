//Find
		void		SendPartyUnlinkOneToAll(LPCHARACTER ch);
	
///Add
#if defined(VOICE_CHAT)
		void		SendPartyVoiceToAll(LPCHARACTER ch, int msg);
		void		MutePlayer(LPCHARACTER leader, LPCHARACTER ch);
		void		UnMutePlayer(LPCHARACTER leader, LPCHARACTER ch);
		bool		IsMuted(LPCHARACTER ch);
#endif

//Find
		DWORD		m_dwLeaderPID;
		
///Add
#if defined(VOICE_CHAT)
		DWORD		VoiceChatTime;
		std::vector<LPCHARACTER> mutelist;
#endif