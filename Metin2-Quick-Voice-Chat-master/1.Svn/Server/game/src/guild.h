//Find
		void		SendGuildDataUpdateToAllMember(SQLMsg* pmsg);
		
///Add
#if defined(VOICE_CHAT)
		void		SendGuildVoiceToAll(LPCHARACTER ch, int msg);
		void		MutePlayer(LPCHARACTER leader, LPCHARACTER ch);
		void		UnMutePlayer(LPCHARACTER leader, LPCHARACTER ch);
		bool		IsMuted(LPCHARACTER ch);
#endif

//Find
		int		m_general_count;
		
///Add
#if defined(VOICE_CHAT)
		DWORD	VoiceChatTime;
		std::vector<LPCHARACTER> mutelist;
#endif