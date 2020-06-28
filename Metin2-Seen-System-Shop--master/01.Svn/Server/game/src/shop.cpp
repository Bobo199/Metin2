//Find
	M2_DELETE(m_pGrid);

///Add
#ifdef ENABLE_SHOP_SEEN
	looked.clear();
#endif

//Find
	pack2.owner_vid = owner_vid;

///Add
#ifdef ENABLE_SHOP_SEEN
	if (m_pkPC != ch && find(looked.begin(), looked.end(), ch) == looked.end())
		looked.push_back(ch);
	pack2.looked = m_pkPC ? looked.size() : 0;
#endif