//1.) Search for:
#include "../eterbase/Timer.h"
//2.) Add after:
#ifdef ENABLE_CHAT_LOG_VIEWER
	#include <windows.h>
	#define DIRECTORY_NAME_CHAT_LOG "chat_log"
#endif

//1.) Search for:
	pChatLine->Instance.SetValue(c_szChat);
//2.) Add before:
#ifdef ENABLE_CHAT_LOG_VIEWER
	CPythonChat::Instance().AppendLog(iType, c_szChat);
#endif

//1.) Search for:
CPythonChat::SChatLine* CPythonChat::SChatLine::New()
{
	return ms_kPool.Alloc();
}
//2.) Add after:
#ifdef ENABLE_CHAT_LOG_VIEWER
void CPythonChat::AppendLog(BYTE bType, const char * c_szChat)
{
	if (bType >= CHAT_TYPE_MAX_NUM || !*c_szChat)
		return;

	if (GetFileAttributes(DIRECTORY_NAME_CHAT_LOG) != FILE_ATTRIBUTE_DIRECTORY)
		CreateDirectory(DIRECTORY_NAME_CHAT_LOG, NULL);

	std::string strChatFileName = "chat_log_default";
	switch (bType)
	{
		case CHAT_TYPE_TALKING:
			strChatFileName = "chat_log_talk";
			break;		
		case CHAT_TYPE_INFO:
			strChatFileName = "chat_log_info";
			break;
		case CHAT_TYPE_NOTICE:
			strChatFileName = "chat_log_notice";
			break;
		case CHAT_TYPE_PARTY:
			strChatFileName = "chat_log_party";
			break;
		case CHAT_TYPE_GUILD:
			strChatFileName = "chat_log_guild";
			break;
		case CHAT_TYPE_SHOUT:
			strChatFileName = "chat_log_shout";
			break;
		case CHAT_TYPE_BIG_NOTICE:
			strChatFileName = "chat_log_big_notice";
			break;
	}
	
	char szPathFileName[32];
	snprintf(szPathFileName, sizeof(szPathFileName), "%s/%s.txt", DIRECTORY_NAME_CHAT_LOG, strChatFileName.c_str());

	FILE * file = fopen(szPathFileName, "a+");
	if (!file)
		return;

	time_t ct = time(0);
	char szTimeInfo[30];
	strftime(szTimeInfo, sizeof(szTimeInfo), "%d.%m.%Y / %H:%M:%S", localtime(&ct));

	fprintf(file, "%s | %s\n", szTimeInfo, c_szChat);
	fflush(file);
	fclose(file);
}
#endif