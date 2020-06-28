//Find
		bool SendPointResetPacket();
		
///Add
#if defined(VOICE_CHAT)
		bool SendVoiceChatPacket(BYTE key, BYTE type);
#endif