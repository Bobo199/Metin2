#Find
			self.channelList.InsertItem(channelID, " %s %s" % (channelName, channelState))
			
#Change
			if app.__CHANNEL_STATUS_UPDATE__:
				self.channelList.InsertItem(channelID, " %s %s     |cffADFF2F%d" % (channelName, channelState, channelDataDict["count"]))
			else:
				self.channelList.InsertItem(channelID, " %s %s" % (channelName, channelState))
				
#Find
	def NotifyChannelState(self, addrKey, state):
		...
		...
		
#Change
	if app.__CHANNEL_STATUS_UPDATE__:
		def NotifyChannelState(self, addrKey, state, player_count):
			try:
				stateName=serverInfo.STATE_DICT[state]
			except:
				stateName=serverInfo.STATE_NONE

			regionID=self.__GetRegionID()
			serverID=self.__GetServerID()
			channelID=addrKey%10

			try:
				serverInfo.REGION_DICT[regionID][serverID]["channel"][channelID]["state"] = stateName
				serverInfo.REGION_DICT[regionID][serverID]["channel"][channelID]["count"] = player_count
				self.__RefreshServerStateList()

			except:
				import exception
				exception.Abort(localeInfo.CHANNEL_NOT_FIND_INFO)

	else:
		def NotifyChannelState(self, addrKey, state):
			try:
				stateName=serverInfo.STATE_DICT[state]
			except:
				stateName=serverInfo.STATE_NONE

			regionID=self.__GetRegionID()
			serverID=self.__GetServerID()
			channelID=addrKey%10

			try:
				serverInfo.REGION_DICT[regionID][serverID]["channel"][channelID]["state"] = stateName
				self.__RefreshServerStateList()

			except:
				import exception
				exception.Abort(localeInfo.CHANNEL_NOT_FIND_INFO)