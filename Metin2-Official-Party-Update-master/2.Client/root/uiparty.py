#Add
import app

#Find
	STATE_NAME_DICT =	{	player.PARTY_STATE_ATTACKER : localeInfo.PARTY_SET_ATTACKER,
							player.PARTY_STATE_BERSERKER : localeInfo.PARTY_SET_BERSERKER,
							player.PARTY_STATE_TANKER : localeInfo.PARTY_SET_TANKER,
							player.PARTY_STATE_DEFENDER : localeInfo.PARTY_SET_DEFENDER,
							player.PARTY_STATE_BUFFER : localeInfo.PARTY_SET_BUFFER,
							player.PARTY_STATE_SKILL_MASTER : localeInfo.PARTY_SET_SKILL_MASTER, }
							
#Add
	if app.BL_PARTY_UPDATE:
		class TextToolTip(ui.Window):
			def __init__(self):
				ui.Window.__init__(self, "TOP_MOST")

				textLine = ui.TextLine()
				textLine.SetParent(self)
				if localeInfo.IsARABIC():
					textLine.SetHorizontalAlignRight()
				else:
					textLine.SetHorizontalAlignLeft()
				textLine.SetOutline()
				textLine.Show()
				self.textLine = textLine

			def __del__(self):
				ui.Window.__del__(self)

			def SetText(self, text, x, y):
				self.textLine.SetText(text)
				self.textLine.SetPosition(x, y)
				
#Find
		self.__CreateAffectToolTip()
		
#Add
		if app.BL_PARTY_UPDATE:
			self.tooltipMapName = self.TextToolTip()
			self.tooltipMapName.Hide()
			
#Find
			self.stateButton.SetEvent(ui.__mem_func__(self.OnMouseLeftButtonDown))
			
#Add
			if app.BL_PARTY_UPDATE:
				self.gauge.GaugeImgBoxAddFlag("not_pick")
				
#Find
		self.attackerButton = None
		
#Add
		if app.BL_PARTY_UPDATE:
			self.tooltipMapName = None
			
#Find
	def OnAffectOverOut(self, index):
		self.affectToolTip.HideToolTip()
		
#Add
	if app.BL_PARTY_UPDATE:		
		def SetCurrentMapName(self, MapName):
			(x, y) = self.GetGlobalPosition()
			self.tooltipMapName.SetText(MapName, x+110, y+2)
			
		def OnMouseOverIn(self):
			self.tooltipMapName.Show()
			
		def OnMouseOverOut(self):
			self.tooltipMapName.Hide()
			
#Find
	def AddPartyMember(self, pid, name):
		board = self.__FindPartyMemberInfoBoardByPID(pid)
		
		if None == board:
		
			board = PartyMemberInfoBoard()
			board.SetParent(self)
			board.SetCharacterPID(pid)
			
			self.partyMemberInfoBoardList.append(board)
			self.__ArrangePartyMemberInfoBoard()
			self.UpdateRect()
		
		if not name:
			name = localeInfo.PARTY_MEMBER_OFFLINE
		
		board.SetCharacterName(name)
		
		board.Unlink()
		
		self.Show()
		self.partyMenuButton.Show()
		
#Change
	if app.BL_PARTY_UPDATE:
		def AddPartyMember(self, pid, name, mapIdx, channel):
			board = self.__FindPartyMemberInfoBoardByPID(pid)
			if None == board:
		
				board = PartyMemberInfoBoard()
				board.SetParent(self)
				board.SetCharacterPID(pid)
		
				self.partyMemberInfoBoardList.append(board)
				self.__ArrangePartyMemberInfoBoard()
				self.UpdateRect()
			
			if not name:
				name = localeInfo.PARTY_MEMBER_OFFLINE
				
			view_channel = channel
			if 99 == channel or mapIdx > 10000:
				view_channel = 0
				
			if mapIdx > 10000:
				mapIdx = mapIdx/10000;
				
			if mapIdx==0:
				MapName = localeInfo.PARTY_MEMBER_OFFLINE
				board.SetCurrentMapName(MapName)
			elif mapIdx in localeInfo.MINIMAP_ZONE_NAME_DICT_BY_IDX:
				MapName = localeInfo.MINIMAP_ZONE_NAME_DICT_BY_IDX[mapIdx]
				board.SetCurrentMapName( "CH-"+str(view_channel) + " " + MapName )
			else:
				board.SetCurrentMapName(str(mapIdx))
			
			if 0 == channel:
				board.Unlink()
			else:
				board.Link()
				
			board.SetCharacterName(name)
			self.Show()
			self.partyMenuButton.Show()
	else:
		def AddPartyMember(self, pid, name):		
			board = self.__FindPartyMemberInfoBoardByPID(pid)
			
			if None == board:
			
				board = PartyMemberInfoBoard()
				board.SetParent(self)
				board.SetCharacterPID(pid)
				
				self.partyMemberInfoBoardList.append(board)
				self.__ArrangePartyMemberInfoBoard()
				self.UpdateRect()
			
			if not name:
				name = localeInfo.PARTY_MEMBER_OFFLINE
			
			board.SetCharacterName(name)
			
			board.Unlink()
			
			self.Show()
			self.partyMenuButton.Show()
			
#Find
	def LinkPartyMember(self, pid, vid):
		board = self.__FindPartyMemberInfoBoardByPID(pid)
		
		if None == board:
			return
		
		board.Link()
		board.SetCharacterVID(vid)
		
#Change
	if app.BL_PARTY_UPDATE:
		def LinkPartyMember(self, pid, vid,mapIdx, channel):
		
			board = self.__FindPartyMemberInfoBoardByPID(pid)
		
			if None == board:
				return
			
			if 99 == channel or mapIdx > 10000:
				channel = 0
				
			if mapIdx > 10000:
				mapIdx = mapIdx/10000
						
			board.Link()
			board.SetCharacterVID(vid)
			
			if mapIdx==0:
				MapName = localeInfo.PARTY_MEMBER_OFFLINE
				board.SetCurrentMapName(MapName)
			elif mapIdx in localeInfo.MINIMAP_ZONE_NAME_DICT_BY_IDX:
				MapName = localeInfo.MINIMAP_ZONE_NAME_DICT_BY_IDX[mapIdx]
				board.SetCurrentMapName( "CH-"+str(channel) + " " + MapName )
			else:
				board.SetCurrentMapName(str(mapIdx))
	else:
		def LinkPartyMember(self, pid, vid):
			
			board = self.__FindPartyMemberInfoBoardByPID(pid)
			
			if None == board:
				return
			
			board.Link()
			board.SetCharacterVID(vid)
