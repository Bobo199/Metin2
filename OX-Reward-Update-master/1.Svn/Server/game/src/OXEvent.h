//Find
	std::vector<std::vector<tag_Quiz> > m_vec_quiz;
	
///Add
#ifdef OX_REWARD_UPDATE		
		struct OX_reward {
			OX_reward() {
				item = 0;
				count = 1;
				gold = 0;
			}
			DWORD item;
			DWORD count;
			DWORD gold;
		};
		std::map<BYTE, std::vector<OX_reward>> m_ox_reward;
#endif

//Find
		void Destroy();
	
///Add
#ifdef OX_REWARD_UPDATE
		bool GiveReward();
		void LoadRewardTable();
#endif