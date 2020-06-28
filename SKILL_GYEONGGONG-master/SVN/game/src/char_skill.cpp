// Search  

if (dwNextSkillUsableTime && dwNextSkillUsableTime<get_dword_time() && dwVnum != SKILL_MUYEONG && dwVnum != SKILL_HORSE_WILDATTACK)

//in the function:

bool TSkillUseInfo::HitOnce(DWORD dwVnum)
{

//Replace with

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
	if (dwNextSkillUsableTime && dwNextSkillUsableTime<get_dword_time() && dwVnum != SKILL_MUYEONG && dwVnum != SKILL_HORSE_WILDATTACK && dwVnum != SKILL_GYEONGGONG)
#else
	if (dwNextSkillUsableTime && dwNextSkillUsableTime<get_dword_time() && dwVnum != SKILL_MUYEONG && dwVnum != SKILL_HORSE_WILDATTACK)
#endif

//Search

int CHARACTER::ComputeSkill(DWORD dwVnum, LPCHARACTER pkVictim, BYTE bSkillLevel)

//Add Before

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
int CHARACTER::ComputeGyeongGongSkill(DWORD dwVnum, LPCHARACTER pkVictim, BYTE bSkillLevel)
{
	if (IsPolymorphed())
		return BATTLE_NONE;

	if (g_bSkillDisable)
		return BATTLE_NONE;

	CSkillProto* pkSk = CSkillManager::instance().Get(dwVnum);

	if (!pkSk)
		return BATTLE_NONE;

	if (IS_SET(pkSk->dwFlag, SKILL_FLAG_SELFONLY))
		pkVictim = this;

	if (!pkVictim)
	{
		if (test_server)
			sys_log(0, "ComputeGyeongGongSkill: %s Victim == null, skill %d", GetName(), dwVnum);

		return BATTLE_NONE;
	}

	if (0 == bSkillLevel)
	{
		if ((bSkillLevel = GetSkillLevel(pkSk->dwVnum)) == 0)
		{
			if (test_server)
				sys_log(0, "ComputeGyeongGongSkill: name:%s vnum:%d  skillLevelBySkill : %d ", GetName(), pkSk->dwVnum, bSkillLevel);
			return BATTLE_NONE;
		}
	}

	const float k = 1.0 * GetSkillPower(pkSk->dwVnum, bSkillLevel) * pkSk->bMaxLevel / 100;

	if (pkSk->bSkillAttrType != SKILL_ATTR_TYPE_NORMAL)
		OnMove(true);
	LPITEM pkWeapon = GetWear(WEAR_WEAPON);

	SetPolyVarForAttack(this, pkSk, pkWeapon);
	int iAmount = (int) pkSk->kPointPoly2.Eval();

		// END_OF_ADD_GRANDMASTER_SKILL
	if (iAmount > 0 && dwVnum == SKILL_GYEONGGONG)
	{
		FuncSplashDamage f(pkVictim->GetX(), pkVictim->GetY(), pkSk, this, -iAmount, 0, pkSk->lMaxHit, pkWeapon, m_bDisableCooltime, IsPC()?&m_SkillUseInfo[dwVnum]:NULL, GetSkillPower(dwVnum, bSkillLevel));
		if (pkVictim->GetSectree())
			pkVictim->GetSectree()->ForEachAround(f);
		
		else
		{
			f(pkVictim);
		}
		return BATTLE_DAMAGE;
	}
	return BATTLE_NONE;
}
#endif

//Search

		// END_OF_ADD_GRANDMASTER_SKILL
		return BATTLE_NONE;
	}
}


bool CHARACTER::UseSkill(DWORD dwVnum, LPCHARACTER pkVictim, bool bUseGrandMaster)


//Add before

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
		if (pkSk->bPointOn2 == POINT_NONE && iAmount2 > 0 && dwVnum == SKILL_GYEONGGONG)
		{
			FuncSplashDamage f(pkVictim->GetX(), pkVictim->GetY(), pkSk, this, -iAmount2, 0, pkSk->lMaxHit, pkWeapon, m_bDisableCooltime, IsPC()?&m_SkillUseInfo[dwVnum]:NULL, GetSkillPower(dwVnum, bSkillLevel));
			if (pkVictim->GetSectree())
				pkVictim->GetSectree()->ForEachAround(f);
			
			else
			{
				f(pkVictim);
			}
		}
#endif

//Search in the function:  bool CHARACTER::UseSkill(DWORD dwVnum, LPCHARACTER pkVictim, bool bUseGrandMaster)

		if (false ==
				m_SkillUseInfo[dwVnum].UseSkill(
					bUseGrandMaster,
			   		(NULL != pkVictim && SKILL_HORSE_WILDATTACK != dwVnum) ? pkVictim->GetVID() : NULL,
			   		ComputeCooltime(iCooltime * 1000),
			   		iSplashCount,
			   		lMaxHit))
		{
			if (test_server)
				ChatPacket(CHAT_TYPE_NOTICE, "cooltime not finished %s %d", pkSk->szName, iCooltime);
			return false;
		}

//Replace with

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
		if (dwVnum == SKILL_GYEONGGONG)
		{
			if (false ==
					m_SkillUseInfo[dwVnum].UseSkill(
						bUseGrandMaster,
				   		(NULL != pkVictim && SKILL_HORSE_WILDATTACK != dwVnum) ? pkVictim->GetVID() : NULL,
				   		ComputeCooltime(iCooltime * 1000),
				   		iSplashCount,
				   		25000))
			{
				if (test_server)
					ChatPacket(CHAT_TYPE_NOTICE, "cooltime not finished %s %d", pkSk->szName, iCooltime);
				return false;
			}
		}
		else
		{
			if (false ==
					m_SkillUseInfo[dwVnum].UseSkill(
						bUseGrandMaster,
				   		(NULL != pkVictim && SKILL_HORSE_WILDATTACK != dwVnum) ? pkVictim->GetVID() : NULL,
				   		ComputeCooltime(iCooltime * 1000),
				   		iSplashCount,
				   		lMaxHit))
			{
				if (test_server)
					ChatPacket(CHAT_TYPE_NOTICE, "cooltime not finished %s %d", pkSk->szName, iCooltime);
				return false;
			}

		}
#else
		if (false ==
				m_SkillUseInfo[dwVnum].UseSkill(
					bUseGrandMaster,
			   		(NULL != pkVictim && SKILL_HORSE_WILDATTACK != dwVnum) ? pkVictim->GetVID() : NULL,
			   		ComputeCooltime(iCooltime * 1000),
			   		iSplashCount,
			   		lMaxHit))
		{
			if (test_server)
				ChatPacket(CHAT_TYPE_NOTICE, "cooltime not finished %s %d", pkSk->szName, iCooltime);
			return false;
		}
#endif

// Search

void CHARACTER::StopMuyeongEvent()
{
	event_cancel(&m_pkMuyeongEvent);
}

//Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
EVENTFUNC(skill_gyeongGong_event)
{
	char_event_info* info = dynamic_cast<char_event_info*>( event->info );

	if ( info == NULL )
	{
		sys_err( "skill_gyeongGong_event> <Factor> Null pointer" );
		return 0;
	}

	LPCHARACTER	ch = info->ch;

	if (ch == NULL) { // <Factor>
		return 0;
	}

	if (!ch->IsAffectFlag(AFF_GYEONGGONG))
	{
		ch->StopGyeongGongEvent();
		return 0;
	}

	ch->ComputeGyeongGongSkill(SKILL_GYEONGGONG, ch);
	
	return PASSES_PER_SEC(2);
}

void CHARACTER::StartGyeongGongEvent()
{
	if (m_pkGyeongGongEvent)
		return;

	char_event_info* info = AllocEventInfo<char_event_info>();

	info->ch = this;
	m_pkGyeongGongEvent = event_create(skill_gyeongGong_event, info, PASSES_PER_SEC(1));
}

void CHARACTER::StopGyeongGongEvent()
{
	event_cancel(&m_pkGyeongGongEvent);
}
#endif

