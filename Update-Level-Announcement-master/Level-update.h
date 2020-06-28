
      struct give_gift 
			{
				int 	level; 
				long gold; 
				int gift1; 
				int gift1_count; 
				int gift2; 
				int gift2_count; 
				bool b_notice; 
				const char* message; 
			};
			
			char normal_message[QUERY_MAX_LEN], big_message[QUERY_MAX_LEN];
			snprintf(normal_message, sizeof(normal_message), "<Informations> You reached level [%u]. Congratulations!", GetLevel());
			snprintf(big_message, sizeof(big_message), "<Informations> [CH%d]: [%s] reached level [%u]. Congratulations!", g_bChannel, GetName(), GetLevel());
			
			static give_gift hediye[] =
			{
				{10, 200, 249, 1, 38053, 2, false, "boom!!"},
				{20, 5000, 279, 1, 38454, 5, false, normal_message},
				{105, 50000, 299, 1, 38455, 10, true, big_message},
			};
			
			for (unsigned int i = 0; i < sizeof(hediye) / sizeof(hediye[0]); i++)
			{
				const give_gift& blck = hediye[i];
				if (blck.level == val)
				{
					GiveGold(blck.gold);
					if (blck.gift1 != 0 && blck.gift1_count != 0)
						AutoGiveItem(blck.gift1, blck.gift1_count);
					if (blck.gift2 != 0 && blck.gift2_count != 0)
						AutoGiveItem(blck.gift2, blck.gift2_count);
					if (blck.b_notice)
						SendNotice(blck.message);
					else
						ChatPacket(CHAT_TYPE_NOTICE, blck.message);
				}
			}
