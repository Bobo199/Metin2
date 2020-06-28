#Find
GUILD = 1
#Add
BLOCK = 2

#Find
	def SetKey(self, key):
		self.key = key
			
#Change
	def SetKey(self, key):
		self.key = key
		if app.ENABLE_MESSENGER_BLOCK:
			constInfo.ME_KEY = key
			
#Find
class MessengerFriendItem(MessengerMemberItem):

	def __init__(self, getParentEvent):
		MessengerMemberItem.__init__(self, getParentEvent)

	def CanRemove(self):
		return TRUE

	def OnRemove(self):
		messenger.RemoveFriend(self.key)
		net.SendMessengerRemovePacket(self.key, self.name)
		return TRUE

#Add
if app.ENABLE_MESSENGER_BLOCK:
	class MessengerBlockItem(MessengerMemberItem):

		def __init__(self, getParentEvent):
			MessengerMemberItem.__init__(self, getParentEvent)

		def CanRemove(self):
			return TRUE

		def OnRemove(self):
			messenger.RemoveBlock(self.key)
			net.SendMessengerRemoveBlockPacket(self.key, self.name)
			return TRUE
			
#Find
class MessengerFriendGroup(MessengerGroupItem):

	def __init__(self, getParentEvent):
		MessengerGroupItem.__init__(self, getParentEvent)
		self.SetName(localeInfo.MESSENGER_FRIEND)

	def AppendMember(self, key, name):
		item = MessengerFriendItem(self.getParentEvent)
		return MessengerGroupItem.AppendMember(self, item, key, name)
		
#Add
if app.ENABLE_MESSENGER_BLOCK:
	class MessengerBlockGroup(MessengerGroupItem):

		def __init__(self, getParentEvent):
			MessengerGroupItem.__init__(self, getParentEvent)
			self.SetName(localeInfo.MESSENGER_BLOCK)

		def AppendMember(self, key, name):
			item = MessengerBlockItem(self.getParentEvent)
			return MessengerGroupItem.AppendMember(self, item, key, name)
			
#Find
		self.addFriendButton = self.GetChild("AddFriendButton")
		
#Add
		self.addBlockButton = self.GetChild("BlockFriendButton")
			
#Find
		self.addFriendButton.SetEvent(ui.__mem_func__(self.OnPressAddFriendButton))
		
#Add
		if app.ENABLE_MESSENGER_BLOCK:
			self.addBlockButton.SetEvent(ui.__mem_func__(self.OnPressAddBlockButton))
			
#Find
		if not uiGameOption.MOBILE: #constInfo.SEND_MOBILE_PHONE_MESSAGE_ENABLE:
			self.mobileButton.Hide()
			width = self.GetWidth()
			height = self.GetHeight()
			self.addFriendButton.SetPosition(-60, 30)
			self.whisperButton.SetPosition(-20, 30)
			self.removeButton.SetPosition(20, 30)
			self.guildButton.SetPosition(60, 30)
				
#Replace
		if not uiGameOption.MOBILE: #constInfo.SEND_MOBILE_PHONE_MESSAGE_ENABLE:
			self.mobileButton.Hide()
			width = self.GetWidth()
			height = self.GetHeight()
			if not app.ENABLE_MESSENGER_BLOCK:	
				self.addFriendButton.SetPosition(-60, 30)
				self.whisperButton.SetPosition(-20, 30)
				self.removeButton.SetPosition(20, 30)
				self.guildButton.SetPosition(60, 30)
				
#Find
	def __AddGroup(self):
		member = MessengerFriendGroup(ui.__mem_func__(self.GetSelf))
		member.Open()
		member.Show()
		self.groupList.append(member)

		member = MessengerGuildGroup(ui.__mem_func__(self.GetSelf))
		member.Open()
		member.Show()
		self.groupList.append(member)
		
#Add
		if app.ENABLE_MESSENGER_BLOCK:
			member = MessengerBlockGroup(ui.__mem_func__(self.GetSelf))
			member.Open()
			member.Show()
			self.groupList.append(member)
			
#Find
	def OnCancelAddFriend(self):
		self.friendNameBoard.Close()
		self.friendNameBoard = None
		return TRUE
		
#Add
	if app.ENABLE_MESSENGER_BLOCK:
		def OnPressAddBlockButton(self):
			blockNameBoard = uiCommon.InputDialog()
			blockNameBoard.SetTitle(localeInfo.MESSENGER_ADD_BLOCK_FRIEND)
			blockNameBoard.SetAcceptEvent(ui.__mem_func__(self.OnAddBlock))
			blockNameBoard.SetCancelEvent(ui.__mem_func__(self.OnCancelAddBlock))
			blockNameBoard.Open()
			self.blockNameBoard = blockNameBoard

		def OnAddBlock(self):
			text2 = self.blockNameBoard.GetText()
			if text2:
				net.SendMessengerAddBlockByNamePacket(text2)
			self.blockNameBoard.Close()
			self.blockNameBoard = None
			return TRUE

		def OnCancelAddBlock(self):
			self.blockNameBoard.Close()
			self.blockNameBoard = None
			return TRUE