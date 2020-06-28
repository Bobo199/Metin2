import ui,wndMgr,grp

class TestBlack(ui.BoardWithTitleBar):
	def __init__(self):
		ui.BoardWithTitleBar.__init__(self)
		self.IsLoaded = False
		
		if not self.IsLoaded:
			self.Load()

	def __del__(self):
		ui.BoardWithTitleBar.__del__(self)
		
	def Load(self):
		self.SetSize(250, 250)
		self.SetCenterPosition()
		self.AddFlag('movable')
		self.SetTitleName("TEST BLACK")
		self.SetCloseEvent(self.Close)
		
		Testt = ui.TextLine()
		Testt.SetParent(self)
		Testt.SetEnterToken(True) ###
		Testt.SetText("this is test message\ntest here\ntesttt")
		Testt.SetPosition(75, 55)
		Testt.Show()
		self.Msg = Testt
		
		self.IsLoaded = True

	def Close(self):
		self.Hide()

	def OnPressEscapeKey(self):
		self.Close()
		return True

	def OnPressExitKey(self):
		self.Close()
		return True

t = TestBlack()
t.Show()