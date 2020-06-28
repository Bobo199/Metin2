//Find
int			Chat(LPCHARACTER ch, const char * data, size_t uiBytes);

///Add
#ifdef ENABLE_CHECK_INSULT
		void 		BlockChatInsult(LPCHARACTER ch, const char * data);
#endif