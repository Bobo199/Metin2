//Find
	HEADER_CG_MYSHOP                            = 55, 
	
///Add
#if defined(QUEST_BY_NAME)
	HEADER_CG_QUEST_BYNAME						= 58,
#endif

//Find
typedef struct command_warp
{
	BYTE			bHeader;
} TPacketCGWarp;

///Add
#if defined(QUEST_BY_NAME)
typedef struct command_script_buttonname
{
	BYTE	header;
	char	questname[32 + 1];
} TPacketCGScriptButtonByName;
#endif