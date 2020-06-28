#pragma once
#if defined(VOICE_CHAT)
namespace VoiceMessage {
	struct voicemsg {std::string msg, dir;};
	const std::vector<voicemsg> voiceinfo
	{
		{"Go go go!", "BGM/voicechat/gomsg.mp3"},
		{"Fuck you!", "BGM/voicechat/fuckyou.mp3"},
		{"Mission Failed!", "BGM/voicechat/missionfailed.mp3"},
		{"Okey, Let's Go!", "BGM/voicechat/okletsgo.mp3"},
		{"Negative!", "BGM/voicechat/negative.mp3"},
		{"Follow me.", "BGM/voicechat/followme.mp3"},
	};
}
#endif