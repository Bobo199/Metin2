import dbg
import app
import net

import ui
class ChatSlowMode(ui.ScriptWindow):

	def __init__(self):
		ui.ScriptWindow.__init__(self)

	def __del__(self):
		ui.ScriptWindow.__del__(self)

	def LoadDialog(self):
		pyScrLoader = ui.PythonScriptLoader()
		pyScrLoader.LoadScriptFile(self, "uiscript/chatslowmode.py")
		self.OkeyButton=self.GetChild("AcceptButton")
		self.CancelButton=self.GetChild("CancelButton")
		self.pos=0
		self.type = 0
		self.GaugeChatSlow = self.GetChild("gaugeslow")
		self.TittleBar = self.GetChild("TitleBar")
		self.ValText = self.GetChild("ValText")
		self.GaugeChatSlow.SetSliderPos(0.0)
		self.GaugeChatSlow.SetEvent(ui.__mem_func__(self.OnChangeSlowGauge))
		self.OkeyButton.SetEvent(ui.__mem_func__(self.SetSlowMode))
		self.CancelButton.SetEvent(ui.__mem_func__(self.Close))
		self.TypeButtonList = []
		for bl in xrange(3):
			self.TypeButtonList.append(self.GetChild("type_" + str(bl)))
			self.TypeButtonList[bl].SetToggleUpEvent(lambda arg=bl: self.ChangeType(arg))
			self.TypeButtonList[bl].SetToggleDownEvent(lambda arg=bl: self.ChangeType(arg))
		self.TittleBar.SetCloseEvent(ui.__mem_func__(self.Close))
		self.ChangeType(self.type)
		return 1

	def ChangeType(self, type):
		self.type = type
		for bl in xrange(3):
			if not self.type == bl:
				self.TypeButtonList[bl].SetUp()
			else:
				self.TypeButtonList[bl].Down()
				
		self.OnChangeSlowGauge()
	def Destroy(self):
		self.GaugeChatSlow=0
		self.pos=0
		self.type = 0
		self.OkeyButton=0
		self.TittleBar=0
		self.CancelButton=0
		self.ClearDictionary()
		
	def OnChangeSlowGauge(self):
		self.pos = self.GaugeChatSlow.GetSliderPos() * 100
		if self.GaugeChatSlow.GetSliderPos() == 1:
			self.ValText.SetText("Close Chat")
			self.pos = -1
		elif int(self.pos) == 0:
			self.ValText.SetText("Disable Slow Mode")
		else:
			if self.type == 0:
				self.ValText.SetText("%d seconds" % self.pos)
			elif self.type == 1:
				self.ValText.SetText("%d minute" % self.pos)
			else:
				self.ValText.SetText("%d hour" % self.pos)
	def OpenDialog(self):
		self.SetTop()
		self.SetCenterPosition()
		self.Show()

	def Close(self):
		self.Hide()
		return TRUE

	def SetSlowMode(self):
		if self.type == 1:
			self.pos = int(self.pos)*60
		elif self.type == 2:
			self.pos = int(self.pos)*3600
		net.SendChatPacket("/chat_Slow_mode %d" % self.pos)
		self.Close()

	def OnPressEscapeKey(self):
		self.Close()
		return TRUE
