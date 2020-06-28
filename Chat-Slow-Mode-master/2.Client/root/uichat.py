#Add
if app.CHAT_SLOW_MODE:
	import uiToolTip, uichatslow
	
#Find
	CHAT_WINDOW_WIDTH = 600
	
#Add
	if app.CHAT_SLOW_MODE:
		CHAT_WINDOW_WIDTH += 20
		
#Find
		btnSendWhisper = ui.Button()
	
#Add Above
		if app.CHAT_SLOW_MODE:
			self.btnSlowMode = ui.Button()
			self.btnSlowMode.SetParent(self)
			self.btnSlowMode.SetEvent(ui.__mem_func__(self.ChatSlowMode))
			self.btnSlowMode.Hide()
			self.InformationText = []
			
#Find
	def SetSendWhisperEvent(self, event):
		self.btnSendWhisper.SetEvent(event)
			
#Add
	if app.CHAT_SLOW_MODE:
		def ChatSlowMode(self):
			if str(player.GetName()).find("[") != -1:
				self.interface.OpenChatSlowDialog()
				
		def SetSlowMode(self, var):
			InformationTextArr = [["Slowmode is closed."], ["Chat is closed.","You can not talk."], ["Slowmode is enabled:","Members can send one"]]
			sec = int(var)
			hour = sec / 3600
			sec -= hour * 3600
			min = (sec / 60)
			sec -= min * 60
			if hour > 0 and min > 0:
				InformationTextArr[2].append("message every %d hour and %d min" % (hour, min))
			elif hour > 0 and min == 0:
				InformationTextArr[2].append("message every %d hour." % (hour))
			elif hour == 0 and min > 0 and sec == 0:
				InformationTextArr[2].append("message every %d min" % (min))
			elif min > 0 and sec > 0:
				InformationTextArr[2].append("message every %d min and %d sec" % (min, sec))
			else:
				InformationTextArr[2].append("message every %d seconds." % sec)
			var = int(var)
			if var == -1:
				var = 1
			elif var > 0:
				var = 2		
			self.InformationText = InformationTextArr[var]
			self.btnSlowMode.SetUpVisual("d:/ymir work/ui/game/taskbar/chat_%d_0.png" % var)
			self.btnSlowMode.SetOverVisual("d:/ymir work/ui/game/taskbar/chat_%d_1.png" % var)
			self.btnSlowMode.SetDownVisual("d:/ymir work/ui/game/taskbar/chat_%d_2.png" % var)
			self.tooltipI = uiToolTip.ItemToolTip()
			self.tooltipI.Hide()
			self.tooltipInfo = [self.tooltipI]*len(self.InformationText)
			for i in xrange(len(self.InformationText)):
				self.tooltipInfo[i].AlignHorizonalCenter()
				if i == 0:
					self.tooltipInfo[i].AppendTextLine(self.InformationText[i], 0xffffff00)
				else:
					self.tooltipInfo[i].AppendTextLine(self.InformationText[i])
				self.tooltipInfo[i].Hide()
				
#Find
		self.btnSendWhisper = 0
	
#Add
		if app.CHAT_SLOW_MODE:
			self.btnSlowMode = 0
			
#Find
		self.btnChatLog.SetPosition(self.GetWidth() - 25, 2)
		
#Add
		if app.CHAT_SLOW_MODE:
			self.btnSlowMode.SetPosition(self.GetWidth() - 80, -5)
			self.btnSlowMode.Show()
			
#Find
		self.btnSendWhisper.Hide()
		
#Add
		if app.CHAT_SLOW_MODE:
			self.btnSlowMode.Hide()
		
#Find
	def OnUpdate(self):
	
#Add in
		if app.CHAT_SLOW_MODE:
			(x, y) = self.btnSlowMode.GetGlobalPosition()
			for i in xrange(len(self.InformationText)):
				if self.btnSlowMode.IsIn():
					self.tooltipInfo[i].SetToolTipPosition(x+20, y-10)
					self.tooltipInfo[i].Show()
				else:
					self.tooltipInfo[i].Hide()
					
#Find
		self.chatInputSet.BindInterface(interface)
		
#Add
		if app.CHAT_SLOW_MODE:
			self.interface = interface
