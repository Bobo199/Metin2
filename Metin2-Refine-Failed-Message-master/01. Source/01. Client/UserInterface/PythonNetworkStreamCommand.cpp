//1.1) Search for:
	else if (!strcmpi(szCmd, "ObserverTeamInfo"))
	{
	}
//1.2) Add after:
#ifdef ENABLE_REFINE_MSG_ADD
	else if (!strcmpi(szCmd, "RefineFailedType"))
	{
		if (2 != TokenVector.size())
		{
			TraceError("CPythonNetworkStream::ServerCommand(c_szCommand=%s) - Strange Parameter Count : %s", c_szCommand);
			return;
		}

		const BYTE bType = atoi(TokenVector[1].c_str());
		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_RefineFailedTypeMessage", Py_BuildValue("(i)", bType));	
	}
#endif