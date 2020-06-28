#ifdef RENEWAL_DEAD_PACKET
#include "threeway_war.h"
DWORD CHARACTER::CalculateDeadTime(BYTE type)
{
	//generated from do_restart(cmd_general.cpp)
	if (!m_pkDeadEvent)
		return 0;
	int iTimeToDead = (event_time(m_pkDeadEvent) / passes_per_sec);
	if (type == REVIVE_TYPE_AUTO_TOWN)
		return iTimeToDead-7;
	if (!test_server && type == REVIVE_TYPE_HERE && (!GetWarMap() || GetWarMap()->GetType() == GUILD_WAR_TYPE_FLAG)) {
		if (IsHack(false) && !CThreeWayWar::instance().IsSungZiMapIndex(GetMapIndex()))
			return iTimeToDead - (180 - g_nPortalLimitTime);
		if (iTimeToDead > 170)
			return iTimeToDead - 170;
	}
	if (IsHack(false) && ((!GetWarMap() || GetWarMap()->GetType() == GUILD_WAR_TYPE_FLAG) || !CThreeWayWar::instance().IsSungZiMapIndex(GetMapIndex())))
		return iTimeToDead - (180 - g_nPortalLimitTime);
	if (iTimeToDead > 173) 
		return iTimeToDead - 173;
	return 0;
}
#endif
