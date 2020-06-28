//Find
	void CButton::Enable()
	{
		SetUp();
		m_bEnable = TRUE;
	}

	void CButton::Disable()
	{
		m_bEnable = FALSE;
		if (!m_disableVisual.IsEmpty())
			SetCurrentVisual(&m_disableVisual);
	}
	
///Change
	void CButton::Enable()
	{
		if (!IsDisable()) {
			SetUp();
			m_bEnable = TRUE;
		}
	}

	void CButton::Disable()
	{
		if (IsDisable()) {
			m_bEnable = FALSE;
			if (!m_disableVisual.IsEmpty())
				SetCurrentVisual(&m_disableVisual);
		}
	}