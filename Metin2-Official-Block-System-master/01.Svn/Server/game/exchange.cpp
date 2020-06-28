///Add

#ifdef ENABLE_MESSENGER_BLOCK
#include "messenger_manager.h"
#endif

//Find
bool CHARACTER::ExchangeStart(LPCHARACTER victim)
{
	
///Add
	#ifdef ENABLE_MESSENGER_BLOCK
	if (MessengerManager::instance().CheckMessengerList(GetName(), victim->GetName(), SYST_BLOCK))
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s blokkk"), victim->GetName());
		return false;
	}
	#endif