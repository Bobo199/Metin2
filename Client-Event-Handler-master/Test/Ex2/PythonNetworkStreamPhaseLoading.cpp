//Add
#if defined(CLIENT_PLAYTIME)
#include "EventHandler.h"
auto SendMessageEvent()
{
	const auto &hndl = EventHandler::Instance().GetHandler("PlayMessage");
	if (!hndl)
		return;
	char msg[128];
	int count = hndl->get()->bind; // how many called
	_snprintf(msg, sizeof(msg), "You are active %d minute in this map!", count);
	if (count)
		IAbstractChat::GetSingleton().AppendChat(CHAT_TYPE_INFO, msg);
}
#endif

//Find in : SendEnterGame
	if (!SendSequence())
		return false;
	
///Add
#if defined(CLIENT_PLAYTIME)
	EventHandler::Instance().AddEvent("PlayMessage", std::bind(&SendMessageEvent), 60, -1); // 60-> 1 min, -1 ->endless event
	//EventHandler::Instance().AddEvent("PlayMessage", [&] {SendMessageEvent; }, 60, -1); // 60-> 1 min, -1 ->endless event
#endif

//If your function is a class member like CPythonNetworkStream::SendMessageEvent
//use bind like std::bind(&SendMessageEvent, this)