#1.1 Search for:
	def GetLogoutMemberList(self):
		return filter(lambda arg: not arg.IsOnline(), self.memberList)
#1.1 Add after:
	def GetMemberList(self):
		return self.memberList