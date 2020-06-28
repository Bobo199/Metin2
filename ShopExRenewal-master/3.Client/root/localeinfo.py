#Find
	"NOT_ENOUGH_MONEY_EX" : SHOP_NOT_ENOUGH_MONEY_EX,
	
#Add
	"NOT_ENOUGH_ITEM": SHOP_NOT_ENOUGH_ITEM,
	"NOT_ENOUGH_EXP": SHOP_NOT_ENOUGH_EXP,
	
#Add new funcs
	if app.ENABLE_RENEWAL_SHOPEX:
		def NumberToShopEXP(n):
			if n <= 0 :
				return "0 %s" % ("EXP")
			n = str(n)
			return "%s %s" % ('.'.join([ i-3<0 and str(n)[:i] or str(n)[i-3:i] for i in range(len(str(n))%3, len(str(n))+1, 3) if i ]), "EXP") 