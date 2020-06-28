#Find in class TextLine(Window):
	def SetFontName(self, fontName):
		wndMgr.SetFontName(self.hWnd, fontName)
		
#Add
	if app.WJ_MULTI_TEXTLINE:
		def SetEnterToken(self, bool):
			wndMgr.SetEnterToken(self.hWnd, bool)