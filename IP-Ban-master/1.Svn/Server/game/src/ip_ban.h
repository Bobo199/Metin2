//Find
extern bool IsBanIP(struct in_addr in);

///Add
#ifdef _ENABLE_IPBAN_
extern void AddBanIP(const char* ip);
#endif