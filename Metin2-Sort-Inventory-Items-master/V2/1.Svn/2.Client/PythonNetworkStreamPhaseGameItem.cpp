//Find 
bool CPythonNetworkStream::SendItemUsePacket(TItemPos pos)
{
	...
	...
}

///Add
#ifdef ENABLE_SORT_INVEN
bool CPythonNetworkStream::SortInven(BYTE option)
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGSortInven p;
	p.header = SORT_INVEN;
	p.option = option;

	if (!Send(sizeof(p), &p)) {
		Tracen("Error sort inven packet");
		return false;
	}

	return SendSequence();
}
#endif