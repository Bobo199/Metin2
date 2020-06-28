//1.) Search for:
		int  GetLineStep(DWORD dwID);
//2.) Add after:
#ifdef ENABLE_CHAT_LOG_VIEWER
		void AppendLog(BYTE bType, const char * c_szChat);
#endif