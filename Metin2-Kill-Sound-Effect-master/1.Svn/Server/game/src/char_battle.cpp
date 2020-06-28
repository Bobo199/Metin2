//Find
	if (pkKiller && pkKiller->IsPC())
	{

///Add in
#if defined(PC_KILL_SOUND_EFFECT)
		// if (IsPC() || GetMobRank() >= MOB_RANK_BOSS) {
			const BYTE sEffMax = 13;
			const double TimeLimit = 9.5; // sec

			if (pkKiller->GetPCKillStage() && difftime(get_global_time(), pkKiller->GetPCLastKillTime()) >= TimeLimit)
				pkKiller->SetPCKillStage(0);

			if (pkKiller->GetPCKillStage() < sEffMax)
				pkKiller->SetPCKillStage(pkKiller->GetPCKillStage() + 1);

			pkKiller->ChatPacket(CHAT_TYPE_COMMAND, "kill_sound %d", pkKiller->GetPCKillStage());
			pkKiller->SetPCLastKillTime(get_global_time());
		// }
#endif