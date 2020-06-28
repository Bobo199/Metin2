//Find
	m_dwLeaderPID = 0;
	
///Add
#if defined(VOICE_CHAT)
	VoiceChatTime = 0;
	mutelist.clear();
#endif

//Find
	event_cancel(&m_eventUpdate); 
	
///Add
#if defined(VOICE_CHAT)
	mutelist.clear();
#endif

//Find
void CParty::SendPartyRemoveOneToAll(DWORD pid)
{
	...
}

///Add
#if defined(VOICE_CHAT)
#include "VoiceMessage.h"
void CParty::SendPartyVoiceToAll(LPCHARACTER ch, int msg)
{
	if (!ch || !m_memberMap.size() || msg < 0 || msg >= VoiceMessage::voiceinfo.size())
		return;
	if (IsMuted(ch)) {
		ch->ChatPacket(CHAT_TYPE_INFO, "You muted in this party.");
		return;
	}
	if (VoiceChatTime > get_global_time()) {
		ch->ChatPacket(CHAT_TYPE_INFO, "You need to wait!");
		return;
	}
	std::string mes = std::string(ch->GetName()) + "->[VOICE CHAT]:" + VoiceMessage::voiceinfo[msg].msg;
	for (const auto & it : m_memberMap) {
		if (it.second.pCharacter && it.second.pCharacter->GetDesc()) {
			it.second.pCharacter->ChatPacket(CHAT_TYPE_COMMAND, "voicechat %s", VoiceMessage::voiceinfo[msg].dir.c_str());
			it.second.pCharacter->ChatPacket(CHAT_TYPE_PARTY, mes.c_str());
		}
	}
	VoiceChatTime = get_global_time() + 4; // Change duration
}
void CParty::MutePlayer(LPCHARACTER leader, LPCHARACTER ch)
{
	if (!ch || !leader)
		return;
	if (GetLeaderPID() != leader->GetPlayerID()) {
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
void CParty::UnMutePlayer(LPCHARACTER leader, LPCHARACTER ch)
{
	if (!ch || !leader)
		return;
	if (GetLeaderPID() != leader->GetPlayerID()) {
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
bool CParty::IsMuted(LPCHARACTER ch)
{
	const auto it = std::find(mutelist.begin(),mutelist.end(),ch);
	return it != mutelist.end();
}
#endif