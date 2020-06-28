// Search 

void CInstanceBase::__Warrior_SetGeomgyeongAffect(bool isVisible)

// Add after this function

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
void CInstanceBase::__Assassin_SetGyeongGongAffect(bool isVisible)
{
	if (isVisible)
	{
		if (IsWearingDress())
			return;

		if (m_kAssassin.m_dwGyeongGongEffect)
			__DetachEffect(m_kAssassin.m_dwGyeongGongEffect);

		m_GraphicThingInstance.SetReachScale(1.5f);
		m_kAssassin.m_dwGyeongGongEffect = __AttachEffect(EFFECT_GYEONGGONG_BOOM);
	}
	else
	{
		m_GraphicThingInstance.SetReachScale(1.0f);

		__DetachEffect(m_kAssassin.m_dwGyeongGongEffect);
		m_kAssassin.m_dwGyeongGongEffect = 0;
	}
}
#endif

//Search

		case AFFECT_GYEONGGONG:
		case AFFECT_KWAESOK:
			// 경공술, 쾌속은 뛸때만 Attaching 시킵니다. - [levites]
			if (isVisible)
				if (!IsWalking())
					return;
			break;    
//Replace with

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
		case AFFECT_GYEONGGONG:
			if (isVisible)
			{
				__Assassin_SetGyeongGongAffect(isVisible);
				if (!IsWalking())
					return;
			}
			break;
		case AFFECT_KWAESOK:
			// 경공술, 쾌속은 뛸때만 Attaching 시킵니다. - [levites]
			if (isVisible)
				if (!IsWalking())
					return;
			break;
#else
		case AFFECT_GYEONGGONG:
		case AFFECT_KWAESOK:
			// 경공술, 쾌속은 뛸때만 Attaching 시킵니다. - [levites]
			if (isVisible)
				if (!IsWalking())
					return;
			break;
#endif
