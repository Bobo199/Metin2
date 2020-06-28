///Add
#if defined(VOICE_CHAT)
#include "VoiceMessage.h"
ACMD(do_guild_voice_chat)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));
	if (!ch->GetGuild() || !*arg1)
		return;
	DWORD idx = 0;
	str_to_number(idx, arg1);
	ch->GetGuild()->SendGuildVoiceToAll(ch, idx-1);
}
ACMD(do_party_voice_chat)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));
	if (!ch->GetParty() || !*arg1)
		return;
	DWORD idx = 0;
	str_to_number(idx, arg1);
	ch->GetParty()->SendPartyVoiceToAll(ch,idx-1);
}
ACMD(do_voice_chat)
{
	char arg1[256], arg2[256];
	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));

	if (!*arg1 || !*arg2) {
		ch->ChatPacket(CHAT_TYPE_INFO, "Syntax: <name> <voiceid>");
		return;
	}

	LPCHARACTER tch = CHARACTER_MANAGER::instance().FindPC(arg1);

	if (!tch) {
		ch->ChatPacket(CHAT_TYPE_INFO, "%s not exist", arg1);
		return;
	}
	int idx = 0;
	str_to_number(idx, arg2);
	idx--;
	if (idx < 0 || idx >= VoiceMessage::voiceinfo.size()) {
		ch->ChatPacket(CHAT_TYPE_INFO, "idx:%d , max size:%d", idx+1,VoiceMessage::voiceinfo.size());
		return;
	}
	std::string mes = std::string(ch->GetName()) + "->[VOICE CHAT]:" + VoiceMessage::voiceinfo[idx].msg;
	tch->ChatPacket(CHAT_TYPE_COMMAND, "voicechat %s", VoiceMessage::voiceinfo[idx].dir.c_str());
	tch->ChatPacket(CHAT_TYPE_INFO, mes.c_str());
}
#endif
