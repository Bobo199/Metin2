
//In Server-Side:

	if (MessengerManager::instance().CheckMessengerList(player1name, player2name, SYST_BLOCK))
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("BLOKLANDIN"));
		return;
	}
	if (MessengerManager::instance().CheckMessengerList(player1name, player2name, SYST_FRIEND))
	{
		ChatPacket(CHAT_TYPE_INFO, "This is your friend.");
		return;
	}
//In Client:
	if messenger.IsBlockByName(player2name) or messenger.IsBlockByName(player1name):
		return
		
//In Quest
	if pc.is_blocked(targetname) == true then
		say("This player blocked")
		
	if pc.is_friend(targetname) == true then
		say("This is your friend")