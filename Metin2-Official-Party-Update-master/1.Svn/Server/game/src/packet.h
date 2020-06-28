///You don't need to change packet_party_unlink because don't using at game src

//Find
typedef struct packet_party_add
{
	....
	....
}

///Change
typedef struct packet_party_add
{
	BYTE	header;
	DWORD	pid;
	char	name[CHARACTER_NAME_MAX_LEN+1];
#ifdef BL_PARTY_UPDATE
	DWORD mapidx;
	BYTE channel;
#endif
} TPacketGCPartyAdd;

//Find
typedef struct packet_party_link
{
	....
	....
}

///Change
typedef struct packet_party_link
{
    BYTE header;
    DWORD pid;
    DWORD vid;
#ifdef BL_PARTY_UPDATE
	DWORD mapidx;
	BYTE channel;
#endif
} TPacketGCPartyLink;