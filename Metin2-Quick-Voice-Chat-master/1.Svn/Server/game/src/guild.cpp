//Find
	m_general_count = 0;
	
///Add
#if defined(VOICE_CHAT)
	VoiceChatTime = 0;
	mutelist.clear();
#endif

//Find
void CGuild::SendGuildDataUpdateToAllMember(SQLMsg* pmsg)
{
	...
}

///Add
#if defined(VOICE_CHAT)
#include "VoiceMessage.h"
void CGuild::SendGuildVoiceToAll(LPCHARACTER ch, int msg)
{
	if (!ch || !m_memberOnline.size() || msg < 0 || msg >= VoiceMessage::voiceinfo.size())
		return;
	if (VoiceChatTime > get_global_time()) {
		ch->ChatPacket(CHAT_TYPE_INFO, "You need to wait!");
		return;
	}
	std::string mes = std::string(ch->GetName()) + "->[VOICE CHAT]:" + VoiceMessage::voiceinfo[msg].msg;
	for (const auto & it : m_memberOnline) {
		if (it && it->GetDesc()) {
			it->ChatPacket(CHAT_TYPE_COMMAND, "voicechat %s", VoiceMessage::voiceinfo[msg].dir.c_str());
			it->ChatPacket(CHAT_TYPE_GUILD, mes.c_str());
		}
	}
	VoiceChatTime = get_global_time() + 4; // Change duration
}
void CGuild::MutePlayer(LPCHARACTER leader, LPCHARACTER ch)
{
	if (!ch || !leader)
		return;
	if (GetMember(leader->GetPlayerID())->grade != GUILD_LEADER_GRADE) {
		leader->ChatPacket(CHAT_TYPE_INFO, "You aren't leader!");
		return;
	}
	if (IsMuted(ch)) {
		leader->ChatPacket(CHAT_TYPE_INFO, "He already muted.");
		return;
	}
	mutelist.emplace_back(ch);
	leader->ChatPacket(CHAT_TYPE_INFO, "%s muted in this party.", ch->GetName());
}
void CGuild::UnMutePlayer(LPCHARACTER leader, LPCHARACTER ch)
{
	if (!ch || !leader)
		return;
	if (GetMember(leader->GetPlayerID())->grade != GUILD_LEADER_GRADE) {
		leader->ChatPacket(CHAT_TYPE_INFO, "You aren't leader!");
		return;
	}
	if (!IsMuted(ch)) {
		leader->ChatPacket(CHAT_TYPE_INFO, "He never muted.");
		return;
	}
	mutelist.erase(std::remove(mutelist.begin(), mutelist.end(), ch), mutelist.end());
	leader->ChatPacket(CHAT_TYPE_INFO, "%s unmuted in this party.", ch->GetName());
}
bool CGuild::IsMuted(LPCHARACTER ch)
{
	const auto it = std::find(mutelist.begin(),mutelist.end(),ch);
	return it != mutelist.end();
}
#endif