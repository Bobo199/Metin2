//Find
	if (0 == m_stText.compare(c_szText))
		return;
	
///Add
	m_isBlinking = CTimer::instance().GetCurrentSecond() + 1.5f;

//Find
	if (m_isCursor)
		
///Change

	if (m_isCursor && !(CTimer::instance().GetCurrentSecond() >= m_isBlinking && (ELTimer_GetMSec() / 400) % 2))
	
//Find
	m_isMultiLine = false;
	
///Add
	m_isBlinking = CTimer::instance().GetCurrentSecond();
