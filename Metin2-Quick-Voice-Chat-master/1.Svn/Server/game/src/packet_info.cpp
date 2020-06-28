//Find
	Set(HEADER_CG_FISHING, sizeof(TPacketCGFishing), "Fishing", true);
	
///Add
#if defined(VOICE_CHAT)
	Set(HEADER_CG_VOICE_CHAT, sizeof(TPacketCGVoiceChat), "VoiceChat", true);
#endif	