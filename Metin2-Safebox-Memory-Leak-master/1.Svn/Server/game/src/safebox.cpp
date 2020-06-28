//Find
	if (pkOldGrid)
		m_pkGrid = M2_NEW CGrid(pkOldGrid, 5, m_iSize);
	else
		m_pkGrid = M2_NEW CGrid(5, m_iSize);
	
///Change
	if (pkOldGrid) {
		m_pkGrid = M2_NEW CGrid(pkOldGrid, 5, m_iSize);
		delete pkOldGrid;
	}
	else
		m_pkGrid = M2_NEW CGrid(5, m_iSize);