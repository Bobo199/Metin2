#Find in : class PopupDialog(ui.ScriptWindow):
	def OnIMEReturn(self):
		self.Close()
		return TRUE
		
#Add
	if app.ENABLE_EXTEND_INVEN_SYSTEM:
		def GetTextSize(self):
			if self.message:
				return self.message.GetTextSize()			
			return (0,0)		
		def GetLineHeight(self):
			if self.message:
				return self.message.GetLineHeight()			
			return 0			
		def SetLineHeight(self, Height):
			self.message.SetLineHeight(Height)			
		def GetTextLineCount(self):
			return self.message.GetTextLineCount()
			
#Find in : class QuestionDialog(ui.ScriptWindow):
	def OnPressEscapeKey(self):
		self.Close()
		return TRUE
		
#Add
	if app.ENABLE_EXTEND_INVEN_SYSTEM:
		def GetTextSize(self):
			if self.textLine:
				return self.textLine.GetTextSize()	
			return (0,0)		
		def GetLineHeight(self):
			if self.textLine:
				return self.textLine.GetLineHeight()			
			return 0			
		def SetLineHeight(self, Height):
			self.textLine.SetLineHeight(Height)		
		def GetTextLineCount(self):
			return self.textLine.GetTextLineCount()