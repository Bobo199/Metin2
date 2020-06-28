//Find
	p.bHeader	= HEADER_GC_WARP;
	p.lX	= x;
	p.lY	= y;
	p.lAddr	= lAddr;
	p.wPort	= wPort;
	
///Add
#if defined(__LOADING_TIP__)
	p.l_MapIndex = lMapIndex;
#endif