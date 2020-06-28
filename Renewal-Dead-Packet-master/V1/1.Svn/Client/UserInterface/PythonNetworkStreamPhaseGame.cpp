//Find
			if (false == pkInstMain->GetDuelMode())
			{
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OnGameOver", Py_BuildValue("()"));	
			}
			
///Change
			if (false == pkInstMain->GetDuelMode())
			{
#ifndef RENEWAL_DEAD_PACKET
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OnGameOver", Py_BuildValue("()"));
#else
				unsigned int size = sizeof(DeadPacket.t_d)/sizeof(DeadPacket.t_d[0]);
				PyObject * DeadTimer = PyTuple_New(size);
				for (unsigned int i = 0; i < size; i++)
					PyTuple_SetItem(DeadTimer, i, Py_BuildValue("i", DeadPacket.t_d[i]));
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OnGameOver", Py_BuildValue("(O)", DeadTimer));
#endif
			}