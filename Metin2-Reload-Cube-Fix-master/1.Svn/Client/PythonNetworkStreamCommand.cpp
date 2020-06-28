//Find
		else if ("close" == TokenVector[1])
		{
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_Cube_Close", Py_BuildValue("()"));
		}
///Add

#if defined(CUBE_RELOAD_FIX)
		else if (!TokenVector[1].compare("reload"))
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_Reload_Cube", Py_BuildValue("()"));
#endif