//Find
			case GUILD_SUBHEADER_CG_ADD_MEMBER:
			{
				const DWORD vid = *reinterpret_cast<const DWORD*>(c_pData);
				LPCHARACTER newmember = CHARACTER_MANAGER::instance().Find(vid);

				if (!newmember)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<길드> 그러한 사람을 찾을 수 없습니다."));
					return SubPacketLen;
				}

				if (!ch->IsPC())
					return SubPacketLen;
///Add
				#ifdef ENABLE_MESSENGER_BLOCK
				if (MessengerManager::instance().CheckMessengerList(ch->GetName(), newmember->GetName(), SYST_BLOCK))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s blokkk"), newmember->GetName());
					return SubPacketLen;
				}
				#endif

//Find in void CInputMain::PartyInvite(LPCHARACTER ch, const char * c_pData)
	if (!pInvitee || !ch->GetDesc() || !pInvitee->GetDesc())
	{
		sys_err("PARTY Cannot find invited character");
		return;
	}
	
///Add
	#ifdef ENABLE_MESSENGER_BLOCK
	if (MessengerManager::instance().CheckMessengerList(ch->GetName(), pInvitee->GetName(), SYST_BLOCK))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s blokkk"), pInvitee->GetName());
		return;
	}
	#endif

//Find in int CInputMain::Whisper(LPCHARACTER ch, const char * data, size_t uiBytes)
		else if (pkChr && pkChr->IsBlockMode(BLOCK_WHISPER))
		{
			if (ch->GetDesc())
			{
				TPacketGCWhisper pack;
				pack.bHeader = HEADER_GC_WHISPER;
				pack.bType = WHISPER_TYPE_TARGET_BLOCKED;
				pack.wSize = sizeof(TPacketGCWhisper);
				strlcpy(pack.szNameFrom, pinfo->szNameTo, sizeof(pack.szNameFrom));
				ch->GetDesc()->Packet(&pack, sizeof(pack));
			}
		}
///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		else if (MessengerManager::instance().CheckMessengerList(ch->GetName(), pkChr->GetName(), SYST_BLOCK))
		{
			if (ch->GetDesc())
			{
				TPacketGCWhisper pack;

				char msg_2[CHAT_MAX_LEN + 1];
				snprintf(msg_2, sizeof(msg_2), LC_TEXT("%s'yi blokladim"), pkChr->GetName());
				int len = MIN(CHAT_MAX_LEN, strlen(msg_2) + 1);

				pack.bHeader = HEADER_GC_WHISPER;
				pack.wSize = sizeof(TPacketGCWhisper) + len;
				pack.bType = WHISPER_TYPE_SYSTEM;
				strlcpy(pack.szNameFrom, pinfo->szNameTo, sizeof(pack.szNameFrom));

				TEMP_BUFFER buf;

				buf.write(&pack, sizeof(TPacketGCWhisper));
				buf.write(msg_2, len);
				ch->GetDesc()->Packet(buf.read_peek(), buf.size());
			}
		}
		#endif

//Find
int CInputMain::Messenger(LPCHARACTER ch, const char* c_pData, size_t uiBytes)
{
	
///Replace
int CInputMain::Messenger(LPCHARACTER ch, const char* c_pData, size_t uiBytes)
{
	TPacketCGMessenger* p = (TPacketCGMessenger*) c_pData;
	
	if (uiBytes < sizeof(TPacketCGMessenger))
		return -1;

	c_pData += sizeof(TPacketCGMessenger);
	uiBytes -= sizeof(TPacketCGMessenger);

	switch (p->subheader)
	{
		#ifdef ENABLE_MESSENGER_BLOCK
		case MESSENGER_SUBHEADER_CG_ADD_BLOCK_BY_VID:
			{
				if (uiBytes < sizeof(TPacketCGMessengerAddBlockByVID))
					return -1;

				TPacketCGMessengerAddBlockByVID * p2 = (TPacketCGMessengerAddBlockByVID *) c_pData;
				LPCHARACTER ch_companion = CHARACTER_MANAGER::instance().Find(p2->vid);

				if (!ch_companion)
					return sizeof(TPacketCGMessengerAddBlockByVID);

				if (ch->IsObserverMode())
					return sizeof(TPacketCGMessengerAddBlockByVID);

				LPDESC d = ch_companion->GetDesc();

				if (!d)
					return sizeof(TPacketCGMessengerAddByVID);

				if (ch_companion->GetGuild() == ch->GetGuild() && ch->GetGuild() != NULL && ch_companion->GetGuild() != NULL)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("lonca olmaz"));
					return sizeof(TPacketCGMessengerAddBlockByVID);
				}
				
				if (MessengerManager::instance().CheckMessengerList(ch->GetName(), ch_companion->GetName(), SYST_FRIEND))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("arkadas ekleyemezsin."));
					return sizeof(TPacketCGMessengerAddBlockByVID);
				}
				
				if (MessengerManager::instance().CheckMessengerList(ch->GetName(), ch_companion->GetName(), SYST_BLOCK))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("zaten bloklu"));
					return sizeof(TPacketCGMessengerAddBlockByVID);
				}
				
				if (ch->GetGMLevel() == GM_PLAYER && ch_companion->GetGMLevel() != GM_PLAYER)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("gm'ye bu yanlis yapilmaz."));
					return sizeof(TPacketCGMessengerAddByVID);
				}

				if (ch->GetDesc() == d) // 자신은 추가할 수 없다.
					return sizeof(TPacketCGMessengerAddBlockByVID);

				MessengerManager::instance().AddToBlockList(ch->GetName(), ch_companion->GetName());
			}
			return sizeof(TPacketCGMessengerAddBlockByVID);

		case MESSENGER_SUBHEADER_CG_ADD_BLOCK_BY_NAME:
			{
				if (uiBytes < CHARACTER_NAME_MAX_LEN)
					return -1;

				char name[CHARACTER_NAME_MAX_LEN + 1];
				strlcpy(name, c_pData, sizeof(name));
				
				if (gm_get_level(name) != GM_PLAYER)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("gm'ye bu yanlis yapilmaz."));
					return CHARACTER_NAME_MAX_LEN;
				}

				LPCHARACTER tch = CHARACTER_MANAGER::instance().FindPC(name);
				
				if (!tch)
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s yok ki."), name);
				else
				{
					if (tch == ch) // 자신은 추가할 수 없다.
						return CHARACTER_NAME_MAX_LEN;
						
					if (tch->GetGuild() == ch->GetGuild() && ch->GetGuild() != NULL && tch->GetGuild() != NULL)
					{
						ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("lonca olmaz"));
						return CHARACTER_NAME_MAX_LEN;
					}
					
					if (MessengerManager::instance().CheckMessengerList(ch->GetName(), tch->GetName(), SYST_FRIEND))
					{
						ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("arkadas ekleyemezsin."));
						return CHARACTER_NAME_MAX_LEN;
					}
						
					MessengerManager::instance().AddToBlockList(ch->GetName(), tch->GetName());
				}
			}
			return CHARACTER_NAME_MAX_LEN;

		case MESSENGER_SUBHEADER_CG_REMOVE_BLOCK:
			{
				if (uiBytes < CHARACTER_NAME_MAX_LEN)
					return -1;

				char char_name[CHARACTER_NAME_MAX_LEN + 1];
				strlcpy(char_name, c_pData, sizeof(char_name));
				
				if (!MessengerManager::instance().CheckMessengerList(ch->GetName(), char_name, SYST_BLOCK))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("bloklu degil"));
					return CHARACTER_NAME_MAX_LEN;
				}
				MessengerManager::instance().RemoveFromBlockList(ch->GetName(), char_name);
			}
			return CHARACTER_NAME_MAX_LEN;
		#endif
		
		case MESSENGER_SUBHEADER_CG_ADD_BY_VID:
			{
				if (uiBytes < sizeof(TPacketCGMessengerAddByVID))
					return -1;

				TPacketCGMessengerAddByVID * p2 = (TPacketCGMessengerAddByVID *) c_pData;
				LPCHARACTER ch_companion = CHARACTER_MANAGER::instance().Find(p2->vid);

				if (!ch_companion)
					return sizeof(TPacketCGMessengerAddByVID);

				if (ch->IsObserverMode())
					return sizeof(TPacketCGMessengerAddByVID);

				if (ch_companion->IsBlockMode(BLOCK_MESSENGER_INVITE))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("상대방이 메신져 추가 거부 상태입니다."));
					return sizeof(TPacketCGMessengerAddByVID);
				}

				LPDESC d = ch_companion->GetDesc();

				if (!d)
					return sizeof(TPacketCGMessengerAddByVID);

				if (ch->GetGMLevel() == GM_PLAYER && ch_companion->GetGMLevel() != GM_PLAYER)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<메신져> 운영자는 메신져에 추가할 수 없습니다."));
					return sizeof(TPacketCGMessengerAddByVID);
				}

				if (ch->GetDesc() == d) // 자신은 추가할 수 없다.
					return sizeof(TPacketCGMessengerAddByVID);
					
				if (MessengerManager::instance().CheckMessengerList(ch->GetName(), ch_companion->GetName(), SYST_FRIEND))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("zaten arkadas."));
					return sizeof(TPacketCGMessengerAddByVID);
				}
				
				if (MessengerManager::instance().CheckMessengerList(ch->GetName(), ch_companion->GetName(), SYST_BLOCK))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("blok ekleyemezsin"));
					return sizeof(TPacketCGMessengerAddByVID);
				}

				MessengerManager::instance().RequestToAdd(ch, ch_companion);
			}
			return sizeof(TPacketCGMessengerAddByVID);

		case MESSENGER_SUBHEADER_CG_ADD_BY_NAME:
			{
				if (uiBytes < CHARACTER_NAME_MAX_LEN)
					return -1;

				char name[CHARACTER_NAME_MAX_LEN + 1];
				strlcpy(name, c_pData, sizeof(name));

				if (ch->GetGMLevel() == GM_PLAYER && gm_get_level(name) != GM_PLAYER)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<메신져> 운영자는 메신져에 추가할 수 없습니다."));
					return CHARACTER_NAME_MAX_LEN;
				}

				LPCHARACTER tch = CHARACTER_MANAGER::instance().FindPC(name);

				if (!tch)
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s 님은 접속되 있지 않습니다."), name);
				else
				{
					if (tch == ch) // 자신은 추가할 수 없다.
						return CHARACTER_NAME_MAX_LEN;

					if (tch->IsBlockMode(BLOCK_MESSENGER_INVITE) == true)
					{
						ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("상대방이 메신져 추가 거부 상태입니다."));
					}
					else
					{
						if (MessengerManager::instance().CheckMessengerList(ch->GetName(), tch->GetName(), SYST_FRIEND))
						{
							ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("zaten arkadas."));
							return CHARACTER_NAME_MAX_LEN;
						}
						
						if (MessengerManager::instance().CheckMessengerList(ch->GetName(), tch->GetName(), SYST_BLOCK))
						{
							ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("blok ekleyemezsin"));
							return CHARACTER_NAME_MAX_LEN;
						}
						// 메신저가 캐릭터단위가 되면서 변경
						MessengerManager::instance().RequestToAdd(ch, tch);
					}
				}
			}
			return CHARACTER_NAME_MAX_LEN;

		case MESSENGER_SUBHEADER_CG_REMOVE:
			{
				if (uiBytes < CHARACTER_NAME_MAX_LEN)
					return -1;

				char char_name[CHARACTER_NAME_MAX_LEN + 1];
				strlcpy(char_name, c_pData, sizeof(char_name));
				if (!MessengerManager::instance().CheckMessengerList(ch->GetName(), char_name, SYST_FRIEND))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("arkadas degil"));
					return CHARACTER_NAME_MAX_LEN;
				}
				MessengerManager::instance().RemoveFromList(ch->GetName(), char_name);
			}
			return CHARACTER_NAME_MAX_LEN;

		default:
			sys_err("CInputMain::Messenger : Unknown subheader %d : %s", p->subheader, ch->GetName());
			break;
	}

	return 0;
}