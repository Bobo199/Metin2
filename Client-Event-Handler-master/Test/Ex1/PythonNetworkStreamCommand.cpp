#include "EventHandler.h"
....

//Find
	else if (!strcmpi(szCmd, "gift"))
	{
		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "Gift_Show", Py_BuildValue("()"));
	}
	
///Change
	else if (!strcmpi(szCmd, "gift"))
	{
		//PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "Gift_Show", Py_BuildValue("()"));
		EventHandler::Instance().AddEvent("exampletest",[]() 
		{
			IAbstractChat::GetSingleton().AppendChat(CHAT_TYPE_INFO, "Test Message");
		}, 5, 10 ); // ten time, delay 5 sec.
	}
	
//use in game /gift