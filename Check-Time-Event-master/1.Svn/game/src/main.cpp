//Find
	if (!(pulse % (passes_per_sec + 4)))
		CHARACTER_MANAGER::instance().ProcessDelayedSave();
	
///Add
#if defined(CHECK_TIME_EVENT)
	if (!(pulse % (passes_per_sec + 1)))
		DESC_MANAGER::instance().CheckTimeEvent();
#endif