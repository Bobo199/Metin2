//Find
bool IsBanIP(struct in_addr in)
{
	...
	...
}

///Add
#ifdef _ENABLE_IPBAN_
void AddBanIP(const char* ip)
{
	const char* filename = "/usr/game/auth/BANIP";
	FILE* fp = fopen(filename, "a");
	if (fp) {
		fprintf(fp, "%s\n", ip);
		fclose(fp);
	}
	else
		sys_log(0, "cannot open BANIP");
}
#endif
