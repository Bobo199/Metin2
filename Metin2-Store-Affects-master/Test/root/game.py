		onPressKeyDict[app.DIK_F5]	= lambda : self.TestStoreAffect()
#####################################################################
	def TestStoreAffect(self):
		if self.affectShower.CheckAffect(chr.NEW_AFFECT_AUTO_HP_RECOVERY):
			chat.AppendChat(chat.CHAT_TYPE_INFO, "activated")
		else:
			chat.AppendChat(chat.CHAT_TYPE_INFO, "deactivated")