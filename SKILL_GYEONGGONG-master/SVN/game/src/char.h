// Search

int					ComputeSkill(DWORD dwVnum, LPCHARACTER pkVictim, BYTE bSkillLevel = 0);

// Add before

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
		int					ComputeGyeongGongSkill(DWORD dwVnum, LPCHARACTER pkVictim, BYTE bSkillLevel = 0);
#endif

// Search

	public:
		void				StartMuyeongEvent();
		void				StopMuyeongEvent();

// Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
		void				StartGyeongGongEvent();
		void				StopGyeongGongEvent();
#endif

//Search

	private:
		LPEVENT				m_pkMuyeongEvent;

// Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
		LPEVENT				m_pkGyeongGongEvent;
#endif
