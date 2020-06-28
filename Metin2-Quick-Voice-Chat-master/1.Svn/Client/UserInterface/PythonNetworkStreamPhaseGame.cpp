//Find
void CPythonNetworkStream::ToggleGameDebugInfo()
{
	...
}

///Add
#if defined(VOICE_CHAT)
bool CPythonNetworkStream::SendVoiceChatPacket(BYTE key, BYTE type)
{
	if (!__CanActMainInstance())	return true;
	TPacketCGVoiceChat	packet;
	packet.header		= HEADER_CG_VOICE_CHAT;
	packet.arg1			= key-1;
	packet.arg2			= type;
	if (!Send(sizeof(packet), &packet)) {
		Tracef("send_voice_chat_packet Error\n");
		return false;
	}
	return SendSequence();
}
#endif