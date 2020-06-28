// Search

void CInstanceBase::StartWalking()
{
	m_GraphicThingInstance.Move();

	if (IsAffect(AFFECT_GYEONGGONG))
	{
		m_adwCRCAffectEffect[AFFECT_GYEONGGONG] = __EffectContainer_AttachEffect(EFFECT_AFFECT_GYEONGGONG);
    
// Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
		__Assassin_SetGyeongGongAffect(true);
#endif

// Search

BOOL CInstanceBase::IsWaiting()
{

// Add after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
	if (IsAffect(AFFECT_GYEONGGONG))
	{
		__Assassin_SetGyeongGongAffect(true);
	}
#endif
