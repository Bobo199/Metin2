#Find
	def __ShowJobToolTip(self):
		self.toolTipJob.ShowToolTip()
	
#Add
	if app.SKILL_COOLTIME_UPDATE:
		def SkillClearCoolTime(self, slotIndex):
			slotIndex = self.__GetRealSkillSlot(player.GetSkillGrade(slotIndex), slotIndex)
			for slotWindow in self.skillPageDict.values():
				if slotWindow.HasSlot(slotIndex):
					slotWindow.SetSlotCoolTime(slotIndex, 0)