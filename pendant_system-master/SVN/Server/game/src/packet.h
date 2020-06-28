// Search

typedef struct packet_target
{
	...
} TPacketGCTarget;


// Add before } TPacketGCTarget;

#ifdef ELEMENT_TARGET
	BYTE	bElement;
#endif
