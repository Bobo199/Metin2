//Find
	HEADER_CG_REFINE				= 96,
	
///Add
#if defined(VOICE_CHAT)
	HEADER_CG_VOICE_CHAT			= 98,
#endif

//Find
typedef struct command_position
{
	BYTE	header;
	BYTE	position;
} TPacketCGPosition;

///Add
#if defined(VOICE_CHAT)
typedef struct command_voicechat
{
	BYTE		header;
	BYTE		arg1;
	BYTE		arg2;
} TPacketCGVoiceChat;
#endif