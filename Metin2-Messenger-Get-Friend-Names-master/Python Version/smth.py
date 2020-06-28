def GetFriendNames(self):
	import uiMessenger
	friendNamesList = []

	if self.interface:
		if self.interface.wndMessenger:
			for group in self.interface.wndMessenger.groupList[uiMessenger.FRIEND]:
				for member in group.GetMemberList()[:]:
					friendNamesList.append(member.GetName())

	return tuple(friendNamesList)