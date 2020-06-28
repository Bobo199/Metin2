///Add
#include "../UserInterface/Locale_inc.h"
#include <memory>

//Find
		void HideOutLine();
///Add
#if defined(WJ_MULTI_TEXTLINE)
		void CheckMultiLine();
		void SetEnterToken(bool v) { m_EnterToken = v; }
#endif

//Find
		std::vector<SHyperlink> m_hyperlinkVector;
		
///Add
#if defined(WJ_MULTI_TEXTLINE)
		std::vector<std::shared_ptr<CGraphicTextInstance>> multi_text;
		bool m_EnterToken;
#endif