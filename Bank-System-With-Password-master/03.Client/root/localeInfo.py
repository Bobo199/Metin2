#Find in elif IsEUROPE() and not IsWE_KOREA() and not IsYMIR():
	def REFINE_FAILURE_NO_SOCKET(attachedItemName) :
		return REFINE_FAILURE_NO_SOCKET0 % (attachedItemName)

#Add
	if app.ENABLE_BANK_SYSTEM:
		def NumberToBankString(n) :
			if n <= 0 :
				return "0"

			return "%s" % ('.'.join([ i-3<0 and str(n)[:i] or str(n)[i-3:i] for i in range(len(str(n))%3, len(str(n))+1, 3) if i ]))