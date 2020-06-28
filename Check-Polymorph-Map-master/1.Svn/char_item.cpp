//Find
				if (pMob->m_table.bLevel >= GetLevel() + iPolymorphLevelLimit)
				{
					ChatPacket(CHAT_TYPE_INFO, LC_TEXT("나보다 너무 높은 레벨의 몬스터로는 변신 할 수 없습니다."));
					return false;
				}
				
///Add
				if (!CPolymorphUtils::instance().CheckMap(this)) {
					ChatPacket(CHAT_TYPE_INFO, "Sorry...");
					return false;
				}