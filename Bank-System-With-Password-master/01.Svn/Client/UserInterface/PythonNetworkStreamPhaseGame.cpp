//Find
			case HEADER_GC_EXCHANGE:
				ret = RecvExchangePacket();
				break;
				
///Add
			#ifdef __BANK_SYSTEM__
			case HEADER_GC_BANK:
				ret = RecvBankPacket();
				break;
			#endif
			
//Find

bool CPythonNetworkStream::SendPointResetPacket()
{
	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "StartPointReset", Py_BuildValue("()"));
	return true;
}

///Add
#ifdef __BANK_SYSTEM__
bool CPythonNetworkStream::SendBankStartPacket(const char* pass)
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGBank packet;

	packet.header		= HEADER_CG_BANK;
	packet.subheader	= BANK_SUBHEADER_CG_START;
	packet.arg1	= 0;
	packet.arg2	= 0;
	packet.arg3	= 0;
	packet.arg4	= 0;
	strncpy(packet.pass, pass, sizeof(packet.pass));
	strncpy(packet.pass2, "", sizeof(packet.pass2));

	if (!Send(sizeof(packet), &packet))
	{
		Tracef("send_bank_start_packet Error\n");
		return false;
	}

	return SendSequence();
}
bool CPythonNetworkStream::SendBankChangePassword(const char* old_pass, const char* new_pass)
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGBank packet;

	packet.header		= HEADER_CG_BANK;
	packet.subheader	= BANK_SUBHEADER_CG_CHANGE_PASSWORD;
	packet.arg1	= 0;
	packet.arg2	= 0;
	packet.arg3	= 0;
	packet.arg4	= 0;
	strncpy(packet.pass, old_pass, sizeof(packet.pass));
	strncpy(packet.pass2, new_pass, sizeof(packet.pass2));

	if (!Send(sizeof(packet), &packet))
	{
		Tracef("send_bank_change_password_packet Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::SendBankClosePacket()
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGBank packet;

	packet.header		= HEADER_CG_BANK;
	packet.subheader	= BANK_SUBHEADER_CG_CLOSE;
	packet.arg1	= 0;
	packet.arg2	= 0;
	packet.arg3	= 0;
	packet.arg4	= 0;
	strncpy(packet.pass, "", sizeof(packet.pass));
	strncpy(packet.pass2, "", sizeof(packet.pass2));

	if (!Send(sizeof(packet), &packet))
	{
		Tracef("send_bank_start_packet Error\n");
		return false;
	}

	return SendSequence();
}
bool CPythonNetworkStream::SendBankAddPacket(DWORD yang, DWORD coins, DWORD won)
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGBank	packet;

	packet.header		= HEADER_CG_BANK;
	packet.subheader	= BANK_SUBHEADER_CG_ADD;
	packet.arg1			= yang;
	packet.arg2			= coins;
	packet.arg3			= won;
	packet.arg4			= 0;
	strncpy(packet.pass, "", sizeof(packet.pass));
	strncpy(packet.pass2, "", sizeof(packet.pass2));

	if (!Send(sizeof(packet), &packet))
	{
		Tracef("send_bank_add_packet Error\n");
		return false;
	}

	return SendSequence();
}
bool CPythonNetworkStream::SendBankWithDrawPacket(DWORD yang, DWORD coins, DWORD won)
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGBank	packet;

	packet.header		= HEADER_CG_BANK;
	packet.subheader	= BANK_SUBHEADER_CG_WITHDRAW;
	packet.arg1			= yang;
	packet.arg2			= coins;
	packet.arg3			= won;
	packet.arg4			= 0;
	strncpy(packet.pass, "", sizeof(packet.pass));
	strncpy(packet.pass2, "", sizeof(packet.pass2));

	if (!Send(sizeof(packet), &packet))
	{
		Tracef("send_bank_withdraw_packet Error\n");
		return false;
	}

	return SendSequence();
}
bool CPythonNetworkStream::SendBankSendPacket(const char* name, DWORD yang, DWORD coins, DWORD won)
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGBank		packet;

	packet.header		= HEADER_CG_BANK;
	packet.subheader	= BANK_SUBHEADER_CG_SEND;
	packet.arg1			= 0;
	packet.arg2			= yang;
	packet.arg3			= coins;
	packet.arg4			= won;
	strncpy(packet.pass, name, sizeof(packet.pass));
	strncpy(packet.pass2, "", sizeof(packet.pass2));

	if (!Send(sizeof(packet), &packet))
	{
		Tracef("send_bank_send_packet Error\n");
		return false;
	}

	return SendSequence();
}
bool CPythonNetworkStream::RecvBankPacket()
{
	TPacketGCBank bank_packet;

	if (!Recv(sizeof(bank_packet), &bank_packet))
		return false;

	// PyObject * poArg = Py_BuildValue("(iiii)", bank_packet.arg1, bank_packet.arg2, bank_packet.arg3, bank_packet.arg4);
	switch (bank_packet.subheader)
	{
		case BANK_SUBHEADER_GC_START:
			CBankManager::Instance().SetFields(bank_packet.arg1, 
				bank_packet.arg2, 
				bank_packet.arg3, 
				bank_packet.arg4);
				
			// PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "SetBank_", poArg);
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "InitBank", Py_BuildValue("(b)", true));
		break;
		case BANK_SUBHEADER_GC_UPDATE:
			CBankManager::Instance().SetFields(bank_packet.arg1, 
				bank_packet.arg2, 
				bank_packet.arg3, 
				bank_packet.arg4);
			// PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "SetBank_", poArg);
		break;
		case BANK_SUBHEADER_GC_CLOSE:
			CBankManager::Instance().Reset();
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "InitBank", Py_BuildValue("(b)", false));
			// PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "SetBank_", poArg);
		break;
	};

	return true;
}
#endif