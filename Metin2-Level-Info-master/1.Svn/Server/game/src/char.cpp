//Find
				if (GetParty())
				{
					GetParty()->RequestSetMemberLevel(GetPlayerID(), GetLevel());
				}

///Add
#if defined(LEVEL_INFO)
				const auto lrange = LvlInfoMap.equal_range(val);
				for (auto it = lrange.first; it != lrange.second; ++it)
					ChatPacket(it->second.second, it->second.first.c_str()); // or LC_TEXT
#endif
