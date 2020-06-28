//Find
bool CPythonNetworkStream::SendScriptButtonPacket(unsigned int iIndex)
{
	...
}

///Add
#if defined(QUEST_BY_NAME)
bool CPythonNetworkStream::SendScriptButtonPacketByName(const char* questname)
{
	TPacketCGScriptButtonByName Packet;
	Packet.header = HEADER_CG_QUEST_BYNAME;
	strncpy(Packet.questname, questname, sizeof(Packet.questname) - 1);
	if (!Send(sizeof(TPacketCGScriptButtonByName), &Packet)) {
		Tracen("Send Script Button By Name Packet Error");
		return false;
	}
	return SendSequence();
}
#endif