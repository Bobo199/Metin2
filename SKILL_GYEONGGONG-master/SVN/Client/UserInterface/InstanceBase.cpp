// Search 

void CInstanceBase::__Warrior_Initialize()

// Add after this function

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
void CInstanceBase::__Assassin_Initialize()
{
	m_kAssassin.m_dwGyeongGongEffect = 0;
}
#endif

// Search

void CInstanceBase::__Initialize()
{
	__Warrior_Initialize();

// Aff after

#ifdef ENABLE_NEW_GYEONGGONG_SKILL
	__Assassin_Initialize();
#endif
