#Add
if app.ENABLE_WHISPER_RENEWAL:
	import whisper
	b_name = "Typing."
	
'''Find'''
			self.gamemasterMark = GetObject("gamemastermark")

#Add
			if app.ENABLE_WHISPER_RENEWAL:
				self.typing = GetObject("typing")
				
'''Find in def OpenWithTarget(self, targetName):'''
		self.titleNameEdit.Hide()
		
#Add
		if app.ENABLE_WHISPER_RENEWAL:
			self.SetTimer()
			self.typing.SetText(b_name)
				
'''Find in def OpenWithoutTarget(self, event):'''
		self.gamemasterMark.Hide()
		
#Add
		if app.ENABLE_WHISPER_RENEWAL:
			self.typing.Hide()
			
'''Find in def Minimize(self):'''
		self.Hide()
		
#Add		
		if app.ENABLE_WHISPER_RENEWAL:
			if whisper.IsSended(self.targetName) and self.targetName:
				whisper.Remove(self.targetName)
				
'''Find in def Close(self):'''
		chat.ClearWhisper(self.targetName)
		
#Add
		if app.ENABLE_WHISPER_RENEWAL:
			if whisper.IsSended(self.targetName) and self.targetName:
				whisper.Remove(self.targetName)
				
'''Find'''
	def OnScroll(self):
		chat.SetWhisperPosition(self.targetName, self.scrollBar.GetPos())
		
#Add
	if app.ENABLE_WHISPER_RENEWAL:
		def SetTimer(self):
			self.endTime = time.clock() + 0.4
		def OnUpdate(self):
			if self.targetName and self.chatLine:
				if len(self.chatLine.GetText()) > 0 and not whisper.IsSended(self.targetName):
					whisper.Add(self.targetName)
				elif not len(self.chatLine.GetText()) > 0 and whisper.IsSended(self.targetName):
					whisper.Remove(self.targetName)
				if whisper.CheckName(self.targetName):
					self.typing.Show()
					lastTime = max(0, self.endTime - time.clock())
					if 0 == lastTime:
						if len(self.typing.GetText()) - len(b_name) < 3:
							self.typing.SetText(self.typing.GetText() + ".")
						else:
							self.typing.SetText(b_name)	
						self.SetTimer()
				else:
					self.typing.Hide()
