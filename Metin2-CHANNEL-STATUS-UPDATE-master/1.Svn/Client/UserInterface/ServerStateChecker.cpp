//Find
				PyCallClassMemberFunc(m_poWnd, "NotifyChannelState", Py_BuildValue("(ii)", it->uServerIndex, channelStatus.bStatus));
				
///Change
#if defined(__CHANNEL_STATUS_UPDATE__)
				PyCallClassMemberFunc(m_poWnd, "NotifyChannelState", Py_BuildValue("(iii)", it->uServerIndex, channelStatus.bStatus, channelStatus.player_count));
#else
				PyCallClassMemberFunc(m_poWnd, "NotifyChannelState", Py_BuildValue("(ii)", it->uServerIndex, channelStatus.bStatus));
#endif