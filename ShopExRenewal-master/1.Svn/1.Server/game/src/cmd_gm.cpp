//Find
			case 'f':
				fishing::Initialize();
				break;
				
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
			case 'x':
			{
				char szShopTableExFileName[256];
				snprintf(szShopTableExFileName, sizeof(szShopTableExFileName), "%s/shop_table_ex.txt", LocaleService_GetBasePath().c_str());

				if (CShopManager::instance().ReadShopTableEx(szShopTableExFileName))
					ch->ChatPacket(CHAT_TYPE_INFO, "<ShopTableEx> reloaded.");
				else
					ch->ChatPacket(CHAT_TYPE_INFO, "<ShopTableEx> failed.");
			}
			break;
#endif