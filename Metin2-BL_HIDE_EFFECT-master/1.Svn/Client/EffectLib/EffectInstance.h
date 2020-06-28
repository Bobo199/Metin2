///Add
#include "../UserInterface/Locale_inc.h"

//Find
		void SetEffectDataPointer(CEffectData * pEffectData);
		
///Add
#if defined(__BL_HIDE_EFFECT__)
		void	SetEffectName(const char* Name) { m_EffName.assign(Name); };
		const	std::string& GetEffectName() const { return m_EffName; };
#endif

//Find
		D3DXMATRIX				m_matGlobal;
		
///Add
#if defined(__BL_HIDE_EFFECT__)
		std::string				m_EffName;
#endif