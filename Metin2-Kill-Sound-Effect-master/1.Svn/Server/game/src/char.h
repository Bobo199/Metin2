//Find
	public:
		void				SetStone(LPCHARACTER pkChrStone);
		
///Add Above
#if defined(PC_KILL_SOUND_EFFECT)
	private:
		time_t				m_dwLastPCKillTime;
		BYTE				b_PCKillStage;
	public:
		time_t				GetPCLastKillTime() const { return m_dwLastPCKillTime; }
		void				SetPCLastKillTime(time_t t) { m_dwLastPCKillTime = t; }
		BYTE				GetPCKillStage() const { return b_PCKillStage; }
		void				SetPCKillStage(BYTE st) { b_PCKillStage = st; }
#endif