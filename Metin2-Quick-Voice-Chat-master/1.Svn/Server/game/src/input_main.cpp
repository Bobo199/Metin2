//Find
void CInputMain::Fishing(LPCHARACTER ch, const char* c_pData)
{
	...
}

///Add
#if defined(VOICE_CHAT)
void CInputMain::VoiceChat(LPCHARACTER ch, const char* c_pData)
{
	if (!ch)	
		return;
	const auto p = reinterpret_cast<const TPacketCGVoiceChat*>(c_pData);
	switch (p->arg2) {
		case 1:
			ch->GetParty() ? ch->GetParty()->SendPartyVoiceToAll(ch,p->arg1):ch->ChatPacket(CHAT_TYPE_INFO, "You are not a party member.");
		break;
		case 2:
			ch->GetGuild() ? ch->GetGuild()->SendGuildVoiceToAll(ch,p->arg1):ch->ChatPacket(CHAT_TYPE_INFO, "You are not a guild member.");
		break;
	}
}
#endif

//Find
		case HEADER_CG_HACK:
			Hack(ch, c_pData);
			break;
			
///Add
#if defined(VOICE_CHAT)
		case HEADER_CG_VOICE_CHAT:
			VoiceChat(ch, c_pData);
		break;
#endif