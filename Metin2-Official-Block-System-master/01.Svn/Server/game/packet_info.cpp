//Find

Set(HEADER_GG_MESSENGER_REMOVE,	sizeof(TPacketGGMessenger),	"MessengerRemove", false);

///Add
#ifdef ENABLE_MESSENGER_BLOCK
	Set(HEADER_GG_MESSENGER_BLOCK_ADD,	sizeof(TPacketGGMessenger),	"MessengerBlockAdd", false);
	Set(HEADER_GG_MESSENGER_BLOCK_REMOVE,	sizeof(TPacketGGMessenger),	"MessengerBlockRemove", false);
#endif