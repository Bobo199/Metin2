//Find
					if (m_isEnableChatInsultFilter)
					{
						if (false == pkInstChatter->IsNPC() && false == pkInstChatter->IsEnemy())
						{
							__FilterInsult(p, strlen(p));
						}
					}

///Change
					if (m_isEnableChatInsultFilter)
					{
						if (false == pkInstChatter->IsNPC() && false == pkInstChatter->IsEnemy())
						{
							#ifdef ENABLE_CHECK_INSULT
							CPythonNetworkStream& paket=CPythonNetworkStream::Instance();
							if (paket.IsInsultIn(p))
							{
								paket.BLOCK_INSULT();
								return false;
							}
							#else
							__FilterInsult(p, strlen(p));
							#endif
						}
					}
	
//Find
			if (p)
			{
				if (m_isEnableChatInsultFilter)
					__FilterInsult(p, strlen(p));
			}
///Change
			if (p)
			{
				if (m_isEnableChatInsultFilter)
				#ifdef ENABLE_CHECK_INSULT
				{
					CPythonNetworkStream& paket=CPythonNetworkStream::Instance();
					if (paket.IsInsultIn(p))
					{
						paket.BLOCK_INSULT();
						return false;
					}
				}
				#else
					__FilterInsult(p, strlen(p));
				#endif	
			}

//Find
bool CPythonNetworkStream::SendQuestConfirmPacket(BYTE byAnswer, DWORD dwPID)
{
	TPacketCGQuestConfirm kPacket;
	kPacket.header = HEADER_CG_QUEST_CONFIRM;
	kPacket.answer = byAnswer;
	kPacket.requestPID = dwPID;

	if (!Send(sizeof(kPacket), &kPacket))
	{
		Tracen("SendQuestConfirmPacket Error");
		return false;
	}

	Tracenf(" SendQuestConfirmPacket : %d, %d", byAnswer, dwPID);
	return SendSequence();
}

///Add
#ifdef ENABLE_CHECK_INSULT
bool CPythonNetworkStream::BLOCK_INSULT()
{
	if (!__CanActMainInstance())
		return true;
	
	TPacketCGChatInsult kPacket;
	kPacket.header = HEADER_CG_INSULT_BLOCK;

	if (!Send(sizeof(kPacket), &kPacket))
	{
		Tracen("BLOCK_INSULT Error");
		return false;
	}

	return SendSequence();
}
#endif