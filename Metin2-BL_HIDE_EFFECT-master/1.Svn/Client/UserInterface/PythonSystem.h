//Find
			bool			bShowSalesText;
			
///Add
#if defined(__BL_HIDE_EFFECT__)
			bool			bBuffEffect;
			bool			bSkillEffect;
#endif

//Find
		void							SetShowSalesTextFlag(int iFlag);
		
///Add
#if defined(__BL_HIDE_EFFECT__)
		bool							GetBLEffectOption(std::uint8_t idx);
		void							SetBLEffectOption(std::uint8_t idx, bool ret);
#endif