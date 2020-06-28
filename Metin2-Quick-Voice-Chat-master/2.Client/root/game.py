#Find in : class GameWindow(ui.ScriptWindow):
		self.mapNameShower = None
	
#Add
		if app.VOICE_CHAT:
			self.VoiceChatType = 1
			self.IsEnableVoiceChat = False
			
			voicechatlist = net.GetVoiceChatList()
			self.voicechatinfo = [0 for i in xrange(len(voicechatlist))]
			
			yVoice = 400
			for x in xrange(len(voicechatlist)):
				self.voicechatinfo[x] = ui.TextLine()
				self.voicechatinfo[x].SetPosition(40, yVoice)
				self.voicechatinfo[x].SetText(voicechatlist[x])
				if x == 0:
					self.voicechatinfo[x].SetFontColor(4.0, 0.83, 0)
				yVoice += 15
				
#Find in : def Close(self):
		self.mapNameShower = None
		
#Add
		if app.VOICE_CHAT:
			self.voicechatinfo = []
			self.IsEnableVoiceChat = False
			
#Find
		onPressKeyDict[app.DIK_F]			= lambda : self.__PressFKey()
		
#Add
		if app.VOICE_CHAT:
			onPressKeyDict[app.DIK_Z]		= lambda : self.VoiceChatInfo(1) #Party
			onPressKeyDict[app.DIK_X]		= lambda : self.VoiceChatInfo(2) #Guild
			
#Find
			if num >= 1 and num <= 4:
				self.pressNumber(num-1)
				
#Add BEFORE!!
			if app.VOICE_CHAT and self.VoiceChatType and self.voicechatinfo and self.IsEnableVoiceChat and num < len(self.voicechatinfo):
				net.SendVoiceChatPacket(num,self.VoiceChatType)
				self.VoiceChatInfo()
				return
				
#Add Last of py
	if app.VOICE_CHAT:
		def VoiceChatInfo(self, key = 1):
			if self.voicechatinfo:
				self.VoiceChatType = key
				if key == 1:
					self.voicechatinfo[0].SetText("Party Voice Chat:")
				else:
					self.voicechatinfo[0].SetText("Guild Voice Chat:")
				for i in xrange(len(self.voicechatinfo)):
					if self.voicechatinfo[i].IsShow():
						self.voicechatinfo[i].Hide()
					else:
						self.voicechatinfo[i].Show()
				self.IsEnableVoiceChat = not self.IsEnableVoiceChat