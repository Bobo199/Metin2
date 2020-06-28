// Under function bool CHARACTER::UseSkill(DWORD dwVnum, LPCHARACTER pkVictim, bool bUseGrandMaster) search:

	if (IS_SET(pkSk->dwFlag, SKILL_FLAG_SELFONLY))
		ComputeSkill(dwVnum, this);
#ifdef ENABLE_WOLFMAN_CHARACTER
	else if (IS_SET(pkSk->dwFlag, SKILL_FLAG_PARTY))
		ComputeSkillParty(dwVnum, this);
#endif

// Add before

	if (dwVnum == SKILL_PAERYONG)
		ComputeSkill(dwVnum, pkVictim);
