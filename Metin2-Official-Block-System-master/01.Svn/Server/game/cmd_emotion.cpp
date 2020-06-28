///Add
#ifdef ENABLE_MESSENGER_BLOCK
#include "messenger_manager.h"
#endif

//Find in ACMD(do_emotion_allow)
	DWORD	val = 0; str_to_number(val, arg1);

///Add under
	#ifdef ENABLE_MESSENGER_BLOCK
	LPCHARACTER tch = CHARACTER_MANAGER::instance().Find(val);
	if (!tch)
		return;
	
	if (MessengerManager::instance().CheckMessengerList(ch->GetName(), tch->GetName(), SYST_BLOCK))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s blokkk"), tch->GetName());
		return;
	}
	#endif