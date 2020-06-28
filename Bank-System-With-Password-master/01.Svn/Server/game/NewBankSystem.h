#include "char.h"
#include "config.h"
// #define ENABLE_LC_ENGLISH
class CBankManager : public singleton<CBankManager>
{				
	public:	
		void ReqPass(LPCHARACTER ch, const char* password);
		void ChangeBankPassword(LPCHARACTER ch, const char* old_pass, const char* new_pass);
		void Start(LPCHARACTER ch, bool update);
		void Close(LPCHARACTER ch);
		void Add(LPCHARACTER ch, int b_yang, int b_coins, int b_won);
		void WithDraw(LPCHARACTER ch, int b_yang, int b_coins, int b_won);
		void Send(LPCHARACTER ch, const char* namee, int b_yang, int b_coins, int b_won);
		void HoldALog(LPCHARACTER ch, const char* type, LPCHARACTER tch);
		
	private:
		DWORD 		GetCoins(LPCHARACTER ch);
		const char* GetBankPassword(LPCHARACTER ch);
		const char* YANGG() 	{ return "yang.bank"; }
		const char* COINSS() 	{ return "coins.bank"; }
		const char* WONN()	 	{ return "won.bank"; }
	
	protected:
		int mygold(LPCHARACTER ch) { return ch->GetGold(); }	
		int yang_bank(LPCHARACTER ch) { return ch->GetQuestFlag(YANGG()); }
	#ifdef ENABLE_CHEQUE_SYSTEM
		int won(LPCHARACTER ch) { return ch->GetCheque(); }
	#else
		int won(LPCHARACTER ch) { return 0; }
	#endif
		int won_bank(LPCHARACTER ch) { return ch->GetQuestFlag(WONN()); }
		int coins(LPCHARACTER ch) { return GetCoins(ch); }
		int coins_bank(LPCHARACTER ch) { return ch->GetQuestFlag(COINSS()); }
};