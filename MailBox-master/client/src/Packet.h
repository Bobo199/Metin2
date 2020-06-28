#ifdef MAILING_SYSTEM
enum mail_sys_subheader
{
	MAIL_SUBHEADER_SEND,
	MAIL_SUBHEADER_CHECK_NAME,
	MAIL_SUBHEADER_DELETE_MAILS,
	MAIL_SUBHEADER_OPEN,
	MAIL_SUBHEADER_ADD_DATA,
	MAIL_SUBHEADER_DELETE_MAIL,
	MAIL_SUBHEADER_ACCEPT_MAIL,
	MAIL_SUBHEADER_ACCEPT_MAILS,
	MAIL_SUBHEADER_READ,
	MAIL_SUBHEADER_RELOAD,
	MAILBOX_POST_GET_ITEMS_NOT_ENOUGHT_INVENTORY,
	MAILBOX_POST_DELETE_FAIL_EXIST_ITEMS,
	MAILBOX_POST_GET_ITEMS_WON_OVERFLOW,
	MAILBOX_POST_GET_ITEMS_YANG_OVERFLOW,
	HEADER_CG_MAIL = 200,
	HEADER_GC_MAIL = 206,
};
typedef struct packet_mail_cg
{
	BYTE header;
	BYTE subheader;
	char 	title[100];
	char 	message[100];
	char 	to[100];
	DWORD itemid;
	DWORD gold;
	DWORD won;
} TPacketCGMail;

typedef struct SDataOfRanks
{
	int		type;
	char 	title[100];
	char 	message[100];
	char 	from[100];
	DWORD 	gold;
	DWORD 	won;
	DWORD 	read;
	DWORD	vnum;
	BYTE	count;
	int		day;
#ifdef ENABLE_CHANGE_LOOK_SYSTEM
	DWORD	dwVnum;
#endif
	long	alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TDataOfMailBox;

typedef struct packet_mail_gc
{
	BYTE	header;
	BYTE	subheader;
	int 	m_count;
	TDataOfMailBox line[18]; // for vector
} TPacketGCMail;
#endif