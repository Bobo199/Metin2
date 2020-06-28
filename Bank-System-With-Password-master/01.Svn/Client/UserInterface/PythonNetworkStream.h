//Find
		bool SendPointResetPacket();
		
///Add
		#ifdef __BANK_SYSTEM__
		bool SendBankStartPacket(const char* pass);
		bool SendBankChangePassword(const char* old_pass, const char* new_pass);
		bool SendBankClosePacket();
		bool SendBankAddPacket(DWORD yang, DWORD coins, DWORD won);
		bool SendBankWithDrawPacket(DWORD yang, DWORD coins, DWORD won);
		bool SendBankSendPacket(const char* name, DWORD yang, DWORD coins, DWORD won);		
		bool RecvBankPacket();
		#endif