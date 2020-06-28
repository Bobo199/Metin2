#Find
	def RefreshSkill(self):
		...
		...
	
#Add
	if app.SKILL_COOLTIME_UPDATE:
		def SkillClearCoolTime(self, usedSlotIndex):
			QUICK_SLOT_SLOT_COUNT = 4
			slotIndex = 0
			for slotWindow in self.quickslot:
				for i in xrange(QUICK_SLOT_SLOT_COUNT):
					(Type, Position) = player.GetLocalQuickSlot(slotIndex)
					if Type == player.SLOT_TYPE_SKILL:
						if usedSlotIndex == Position:
							slotWindow.SetSlotCoolTime(slotIndex, 0)
							return
					slotIndex += 1