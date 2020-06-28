//Find in: case SHOP_SUBHEADER_GC_START:
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "StartShop", Py_BuildValue("(i)", dwVID));

///Change
				#ifdef ENABLE_SHOP_SEEN
					DWORD Bakanlar = pShopStartPacket->looked;
					PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "StartShop", Py_BuildValue("(ii)", dwVID, Bakanlar));
				#else
					PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "StartShop", Py_BuildValue("(i)", dwVID));
				#endif