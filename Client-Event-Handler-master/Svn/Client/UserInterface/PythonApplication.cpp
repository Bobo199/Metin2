///Add
#if defined(EVENT_HANDLER_MASTER)
	#include "EventHandler.h"
#endif

//Find
		s_uiLoad = s_dwFaceCount = s_dwUpdateFrameCount = s_dwRenderFrameCount = 0;
	
///Add
#if defined(EVENT_HANDLER_MASTER)
		EventHandler::Instance().Proccess();
#endif
