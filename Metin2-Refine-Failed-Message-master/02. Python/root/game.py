#1.1) Search for:
	def __PartyRequestDenied(self):
		self.PopupMessage(localeInfo.PARTY_REQUEST_DENIED)
#1.2) Add before:
	if app.ENABLE_REFINE_MSG_ADD:
		def BINARY_RefineFailedTypeMessage(self, type):
			REFINE_FAILURE_DICT = {
				player.REFINE_FAIL_GRADE_DOWN: localeInfo.REFINE_FAILURE_GRADE_DOWN,
				player.REFINE_FAIL_DEL_ITEM:   localeInfo.REFINE_FAILURE_DEL_ITEM,
				player.REFINE_FAIL_KEEP_GRADE: localeInfo.REFINE_FAILURE_KEEP_GRADE,
				player.REFINE_FAIL_MAX:        localeInfo.REFINE_FAILURE
			}
			
			snd.PlaySound("sound/ui/jaeryun_fail.wav")
			self.PopupMessage(REFINE_FAILURE_DICT.get(type, player.REFINE_FAIL_MAX))