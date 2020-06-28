///Add
#include "polymorph.h"

//Find
	if (pkAff->dwType == SKILL_MUYEONG)
	{
		if (bAdd)
			StartMuyeongEvent();
		else
			StopMuyeongEvent();
	}
		
///Add
	if (AFFECT_POLYMORPH == pkAff->dwType && !CPolymorphUtils::instance().CheckMap(this))
	{
		SetPolymorph(0);
		RemoveAffect(AFFECT_POLYMORPH);
	}