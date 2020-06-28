//Find
			ch->GetDesc()->Packet(&pack, sizeof(TPacketGCWhisper));
			sys_log(0, "WHISPER: no player");
		
///Change
#ifdef ENABLE_WHISPER_RENEWAL			
			char buf[CHAT_MAX_LEN + 1];
			strlcpy(buf, data + sizeof(TPacketCGWhisper), MIN(iExtraLen + 1, sizeof(buf)));
			if (!(std::string(buf).find("|?whisper_renewal>|") != std::string::npos || std::string(buf).find("|?whisper_renewal<|") != std::string::npos)) {
				ch->GetDesc()->Packet(&pack, sizeof(TPacketGCWhisper));
				sys_log(0, "WHISPER: no player");
			}
#else
			ch->GetDesc()->Packet(&pack, sizeof(TPacketGCWhisper));
			sys_log(0, "WHISPER: no player");
#endif