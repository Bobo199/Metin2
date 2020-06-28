//1.1 Search for:
#include "../eterlib/Camera.h"
//1.1 Add after:
#if defined(ENABLE_TAB_NEXT_TARGET)
	#include "PythonCharacterManager.h"
	#include "PythonPlayer.h"
	#include "InstanceBase.h"
#endif

//1.2 Search for:
	rkWndMgr.RunKeyDown(iIndex);
//1.2 Add before:
#if defined(ENABLE_TAB_NEXT_TARGET)
	if (DIK_TAB == iIndex)
	{
		const auto rkPlayer = CPythonPlayer::InstancePtr();
		if (rkPlayer)
		{
			const auto pkInstTarget = CPythonCharacterManager::Instance().GetTabNextTargetPointer(rkPlayer->NEW_GetMainActorPtr());
			if (pkInstTarget)
				rkPlayer->SetTarget(pkInstTarget->GetVirtualID(), true);
		}
	}
#endif
