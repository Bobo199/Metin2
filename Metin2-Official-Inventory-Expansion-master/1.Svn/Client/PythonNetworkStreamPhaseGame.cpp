//Find
bool CPythonNetworkStream::SendCharacterPositionPacket(BYTE iPosition)
{
	TPacketCGPosition PositionPacket;

	PositionPacket.header = HEADER_CG_CHARACTER_POSITION;
	PositionPacket.position = iPosition;

	if (!Send(sizeof(TPacketCGPosition), &PositionPacket))
	{
		Tracen("Send Character Position Packet Error");
		return false;
	}

	return SendSequence();
}

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
bool CPythonNetworkStream::Envanter_paketi()
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGEnvanter envanterpaketi;
	envanterpaketi.header = ENVANTER_BLACK;

	if (!Send(sizeof(envanterpaketi), &envanterpaketi))
	{
		Tracen("Error system->[Inventory-Expansion]");
		return false;
	}

	return SendSequence();
}
#endif