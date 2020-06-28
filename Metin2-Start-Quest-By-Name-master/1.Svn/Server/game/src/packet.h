//Find
	HEADER_CG_MYSHOP				= 55,
	
///Add
#if defined(QUEST_BY_NAME)
	HEADER_CG_QUEST_BYNAME		 	= 58,
#endif

//Find
typedef struct packet_skill_level
{
	BYTE		bHeader;
	TPlayerSkill	skills[SKILL_MAX_NUM];
} TPacketGCSkillLevel;

///Add
#if defined(QUEST_BY_NAME)
typedef struct command_script_buttonname
{
	BYTE	header;
	char	questname[QUEST_NAME_MAX_LEN + 1];
} TPacketCGScriptButtonByName;
#endif