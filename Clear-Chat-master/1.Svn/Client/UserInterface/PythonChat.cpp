///Add
#ifdef CLEAR_CHAT
void CPythonChat::ClearChat()
{
	std::for_each(m_ChatLineDeque.begin(), m_ChatLineDeque.end(), SChatLine::Delete);
	m_ChatLineDeque.clear();
	m_ShowingChatLineList.clear();
}
#endif