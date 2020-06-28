///Add
#if defined(__BL_HIDE_EFFECT__)
enum { BL_BUFF, BL_SKILL, BL_MAX };
static bool BLDisableEffects[BL_MAX];
static const std::initializer_list<std::string> EffectBlockMap[BL_MAX]
{
	//BUFF
	{
		"d:/ymir work/pc/shaman/effect/3hosin_loop.mse",
		"d:/ymir work/pc/shaman/effect/boho_loop.mse",
		"d:/ymir work/pc/shaman/effect/6gicheon_hand.mse",
		"d:/ymir work/pc/shaman/effect/jeungryeok_hand.mse"
	},
	//SKILL
	{
		"d:/ymir work/pc/shaman/effect/10kwaesok_loop.mse",
		"d:/ymir work/pc/sura/effect/gwigeom_loop.mse",
		"d:/ymir work/pc/sura/effect/fear_loop.mse",
		"d:/ymir work/pc/sura/effect/jumagap_loop.mse",
		"d:/ymir work/pc/sura/effect/muyeong_loop.mse",
		"d:/ymir work/pc/sura/effect/heuksin_loop.mse",
		"d:/ymir work/pc/warrior/effect/gyeokgongjang_loop.mse",
		"d:/ymir work/pc/warrior/effect/geom_sword_loop.mse",
		"d:/ymir work/pc/assassin/effect/gyeonggong_loop.mse",
	},
};
void CEffectManager::HideOnSomeEffects(std::uint8_t Type, bool IsVisible)
{
	BLDisableEffects[Type] = !IsVisible;
}
#endif

//Find in struct CEffectManager_FEffectInstanceRender
		pkEftInst->Render();
		
///Add Above(Üstüne Ekle)!
#if defined(__BL_HIDE_EFFECT__)
		for (std::uint8_t i = 0; i < BL_MAX; i++)
			if (BLDisableEffects[i] && std::find(EffectBlockMap[i].begin(), EffectBlockMap[i].end(), pkEftInst->GetEffectName()) != EffectBlockMap[i].end())
				return;
#endif

//Find in void CEffectManager::CreateEffectInstance(DWORD dwInstanceIndex, DWORD dwID)
	pEffectInstance->SetEffectDataPointer(pEffect);
	
///Add
#if defined(__BL_HIDE_EFFECT__)
	pEffectInstance->SetEffectName(pEffect->GetFileName());
#endif