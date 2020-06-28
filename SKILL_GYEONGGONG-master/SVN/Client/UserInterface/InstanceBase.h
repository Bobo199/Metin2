// Search

			EFFECT_NUM,
		};

		enum
		{
			DUEL_NONE,
			DUEL_CANNOTATTACK,
			DUEL_START,
		};
   
// Add before

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
			EFFECT_GYEONGGONG_BOOM,
#endif

// Search

void __Warrior_SetGeomgyeongAffect(bool isVisible);

// Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
		void __Assassin_SetGyeongGongAffect(bool isVisible);
#endif

// Search

	protected:
		struct SWarrior
		{
			DWORD m_dwGeomgyeongEffect;
		};

		SWarrior m_kWarrior;

		void __Warrior_Initialize();
    
// Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
	protected:
		struct SAssassin
		{
			DWORD m_dwGyeongGongEffect;
		};

		SAssassin m_kAssassin;

		void __Assassin_Initialize();
#endif
