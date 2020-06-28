//Find
		DWORD			GetLastAttackTime() const	{ return m_dwLastAttackTime; }
		
///Add
#if defined(CHAT_SLOW_MODE)
		bool			CheckSlowMode(bool button, BYTE type = 0);
		DWORD			GetLastTalkTime() const	{ return m_dwLastTalkTime; }
		void			SetLastTalkTime(DWORD time) { m_dwLastTalkTime = time; }
#endif

//Find
		DWORD			m_dwLastAttackTime;
		
///Add
#if defined(CHAT_SLOW_MODE)
		DWORD			m_dwLastTalkTime;
#endif		