//Find in bool CPythonNetworkStream::RecvDeadPacket()
		CPythonPlayer::Instance().NotifyDeadMainCharacter();
		
///Add
#if defined(SKILL_COOLTIME_UPDATE)
		CPythonPlayer::Instance().ResetSkillCoolTimes();
#endif