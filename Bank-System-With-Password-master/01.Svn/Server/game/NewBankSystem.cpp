/**
	Start V1: 18.11.16
	Start V2: 27.08.17
	Blackdragonx61-Bank System
**/
#include "stdafx.h"
#include "cmd.h"
#include "desc_manager.h"
#include "char_manager.h"
#include "db.h"
#include "utils.h"
#include "char.h"
#include "questmanager.h"
#include "NewBankSystem.h"
#include "desc.h"
#include "char.h"

char const * EnglishLC[] = {
	"Bank isn't open.",
	"Bank password changed.Your new password is:%s",
	"Password is wrong.",
	"The Bank is already opened.",
	"The Bank is already closed.",
	"You don't have enough yang.",
	"You don't have enough won.",
	"You don't have enough coin.",
	"Target isn't online.",
	"You can't send it to yourself.",
	"You don't have enough yang in your bank.",//10
	"You don't have enough won in your bank.",
	"You don't have enough coin in your bank.",
	"You add to your bank %d yang.",
	"You add to your bank %d won.",
	"You add to your bank %d coin.",
	"You withdraw %d coins.",
	"%s sent %d yang to you.",
	"You sent %d yang to %s",
	"%s sent %d won to you.",
	"You sent %d won to %s",
	"%s sent %d coin to you.",
	"You sent %d coin to %s",
	"You can't add too yang.",
	"You can't add too won.",
	"You can't add too coin.",//25
	"You can't have too yang.",
	"You can't have too won.",
	"Target can't have too yang.",
	"Target can't have too won.",
	"New pass and old pass is same.",
};

DWORD CBankManager::GetCoins(LPCHARACTER ch)
{
	std::auto_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("SELECT coins FROM account.account WHERE id = '%d';", ch->GetDesc()->GetAccountTable().id));
	if (pMsg->Get()->uiNumRows == 0)
		return 0;
	
	MYSQL_ROW row = mysql_fetch_row(pMsg->Get()->pSQLResult);
	DWORD ep = 0;
	str_to_number(ep, row[0]);
	return ep;
}

const char* CBankManager::GetBankPassword(LPCHARACTER ch)
{
	std::auto_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("SELECT bankpass FROM player.player WHERE name = '%s';", ch->GetName()));
	if (pMsg->Get()->uiNumRows == 0)
		return 0;
	
	MYSQL_ROW row = mysql_fetch_row(pMsg->Get()->pSQLResult);
	const char* password = "";
	password = row[0];
	return password;
}

void CBankManager::ChangeBankPassword(LPCHARACTER ch, const char* old_pass, const char* new_pass)
{
	if (!ch->IsBankOpened())
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[0]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Banka acik degil."));	
		#endif
		return;
	}
	if (!*old_pass || strlen(old_pass) > SAFEBOX_PASSWORD_MAX_LEN || !*new_pass || strlen(new_pass) > SAFEBOX_PASSWORD_MAX_LEN)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<창고> 잘못된 암호를 입력하셨습니다."));
		return;
	}
	if (!strcmp(GetBankPassword(ch), old_pass))
	{
		if (!strcmp(new_pass, old_pass))
		{
			#ifdef ENABLE_LC_ENGLISH
			ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[30]);
			#else
			ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Banka sifresi ayni"));
			#endif
			return;
		}
		DBManager::instance().DirectQuery("UPDATE player.player SET bankpass = '%s' WHERE name = '%s';", new_pass, ch->GetName());
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[1], new_pass);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Banka sifresi %s olarak degistirildi."), new_pass);
		#endif
		HoldALog(ch, "ChangePassWord", NULL);
	}
	else
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[2]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Yanlis sifre girdiniz"));
		#endif
		return;
	}
}

void CBankManager::ReqPass(LPCHARACTER ch, const char* password)
{
	if (ch->IsBankOpened())
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[3]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Banka zaten acik."));
		#endif
		return;
	}
	if (!*password || strlen(password) > SAFEBOX_PASSWORD_MAX_LEN)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<창고> 잘못된 암호를 입력하셨습니다."));
		return;
	}

	if (!strcmp(GetBankPassword(ch), password))
	{
		Start(ch, false);
	}
	else
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[2]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Yanlis sifre girdiniz"));
		#endif
		return;
	}
}

void CBankManager::Start(LPCHARACTER ch, bool update)
{
	if (ch->IsBankOpened() && !update)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[3]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Banka zaten acik."));
		#endif
		return;
	}
	TPacketGCBank p;
	p.header = HEADER_GC_BANK;
	if (update)
	{
		p.subheader = BANK_SUBHEADER_GC_UPDATE;
	}
	else
	{
		p.subheader = BANK_SUBHEADER_GC_START;
		ch->bBankOpen = true;
	}
	p.arg1 = yang_bank(ch);
	p.arg2 = coins_bank(ch);
#ifdef ENABLE_CHEQUE_SYSTEM
	p.arg3 = won_bank(ch);
#else
	p.arg3 = 0;
#endif
	p.arg4 = GetCoins(ch);
	ch->GetDesc()->Packet(&p, sizeof(p));
}

void CBankManager::Close(LPCHARACTER ch)
{
	if (!ch->IsBankOpened())
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[4]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Banka zaten kapali"));	
		#endif
		return;
	}
	TPacketGCBank p;
	p.header = HEADER_GC_BANK;
	p.subheader = BANK_SUBHEADER_GC_CLOSE;
	p.arg1 = 0;
	p.arg2 = 0;
	p.arg3 = 0;
	p.arg4 = 0;
	ch->GetDesc()->Packet(&p, sizeof(p));
	ch->bBankOpen = false;
}

void CBankManager::Add(LPCHARACTER ch, int b_yang, int b_coins, int b_won)
{
	if (b_yang < 0)
		b_yang = 0;
	if (b_won < 0)
		b_won = 0;
	if (b_coins < 0)
		b_coins = 0;
	
	if (!(mygold(ch) >= b_yang))
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[5]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("BYeterli yang yok."));	
		#endif
		return;
	}
	if ((yang_bank(ch)+b_yang) >= GOLD_MAX)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[23]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("yang banka sinir sorunu"));
		#endif
		return;
	}
	if (!(won(ch) >= b_won))
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[6]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("BYeterli won yok."));	
		#endif
		return;
	}
	if ((won_bank(ch)+b_won) >= CHEQUE_MAX)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[24]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("won banka sinir sorunu"));
		#endif
		return;
	}
	if (!(coins(ch) >= b_coins))
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[7]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("BYeterli ep yok."));	
		#endif
		return;
	}
	// if ((coins_bank(ch)+b_coins) >= BANK_MAX_COIN)
	// {
		// #ifdef ENABLE_LC_ENGLISH
		// ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[25]);
		// #else
		// ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("ep banka sinir sorunu"));
		// #endif
		// return;
	// }
	
	if (b_yang > 0)
	{
		ch->PointChange(POINT_GOLD, -b_yang, true);
		ch->SetQuestFlag(YANGG(), yang_bank(ch)+b_yang);
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[13], b_yang);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Bankaniza %d yang yatirdiniz."), b_yang);
		#endif
	}
	
	if (b_won > 0)
	{
		ch->PointChange(POINT_CHEQUE, -b_won, true);
		ch->SetQuestFlag(WONN(), won_bank(ch)+b_won);
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[14], b_won);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Bankaniza %d won yatirdiniz."), b_won);
		#endif
	}
	
	if (b_coins > 0)
	{
		std::auto_ptr<SQLMsg> msg(DBManager::instance().DirectQuery("UPDATE account.account SET coins = coins - '%ld' WHERE id = '%d'", b_coins, ch->GetDesc()->GetAccountTable().id));
		ch->SetQuestFlag(COINSS(), coins_bank(ch)+b_coins);
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[15], b_coins);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Bankaniza %d ep yatirdiniz."), b_coins);
		#endif
	}
	
	Start(ch, true);
	HoldALog(ch, "Add", NULL);
}
void CBankManager::WithDraw(LPCHARACTER ch, int b_yang, int b_coins, int b_won)
{
	if (b_yang < 0)
		b_yang = 0;
	if (b_won < 0)
		b_won = 0;
	if (b_coins < 0)
		b_coins = 0;
	
	if (yang_bank(ch) < b_yang)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[5]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("BYeterli yang yok."));	
		#endif
		return;
	}
	if ((mygold(ch) + b_yang) >= GOLD_MAX)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[26]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("yang yer yok"));
		#endif
		return;
	}
	///////
	if (won_bank(ch) < b_won)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[6]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("BYeterli won yok."));	
		#endif
		return;
	}
	if ((won(ch) + b_won) >= CHEQUE_MAX)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[27]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("won yer yok"));
		#endif
		return;
	}
	////
	if (coins_bank(ch) < b_coins)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[7]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("BYeterli ep yok."));	
		#endif
		return;
	}
	
	if (b_yang > 0)
	{
		ch->PointChange(POINT_GOLD, +b_yang, true);
		ch->SetQuestFlag(YANGG(), yang_bank(ch)-b_yang);
	}
	
	if (b_won > 0)
	{
		ch->PointChange(POINT_CHEQUE, +b_won, true);
		ch->SetQuestFlag(WONN(), won_bank(ch)-b_won);
	}
	
	if (b_coins > 0)
	{
		std::auto_ptr<SQLMsg> msg(DBManager::instance().DirectQuery("UPDATE account.account SET coins = coins + '%ld' WHERE id = '%d'", b_coins, ch->GetDesc()->GetAccountTable().id));
		ch->SetQuestFlag(COINSS(), coins_bank(ch)-b_coins);
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[16], b_coins);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, "%d ep kazandiniz", b_coins);
		#endif
	}
	
	Start(ch, true);
	HoldALog(ch, "WithDraw", NULL);
}
void CBankManager::Send(LPCHARACTER ch, const char* namee, int b_yang, int b_coins, int b_won)
{
	//send my bank to tch inventory
	
	LPCHARACTER tch = CHARACTER_MANAGER::instance().FindPC(namee);
	if (!tch)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[8]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Hedef ooyunda degil."));
		#endif
		return;
	}
	if (tch == ch)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[9]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("kendine yollayamazsin.."));
		#endif
		return;
	}
	// if (tch->IsGM())
	// {
		// return;
	// }
	if (b_yang < 0)
		b_yang = 0;
	if (b_won < 0)
		b_won = 0;
	if (b_coins < 0)
		b_coins = 0;
	
	long tchgold = tch->GetGold();
#ifdef ENABLE_CHEQUE_SYSTEM
	long won2 = tch->GetCheque();
#else
	long won2 = 0;
#endif
	long ep2 = GetCoins(tch);
	
	if (yang_bank(ch) < b_yang)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[10]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Gonder banka yang yok"));
		#endif
		return;
	}	
	if ((tchgold + b_yang) >= GOLD_MAX)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[28]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Hedef envanter'inde bu kadar yang tasiyamaz."));
		#endif
		return;
	}
	///
	if (won_bank(ch) < b_won)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[11]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Gonder banka won yok"));
		#endif
		return;
	}	
	if ((won2 + b_won) >= CHEQUE_MAX)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[29]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Hedef envanter'inde bu kadar won tasiyamaz."));
		#endif
		return;
	}
	
	if (coins_bank(ch) < b_coins)
	{
		#ifdef ENABLE_LC_ENGLISH
		ch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[12]);
		#else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Gonder banka ep yok"));
		#endif
		return;
	}
	
	if (b_yang > 0)
	{
		tch->PointChange(POINT_GOLD, +b_yang, true);
		ch->SetQuestFlag(YANGG(), yang_bank(ch)-b_yang);
		#ifdef ENABLE_LC_ENGLISH
		tch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[17], ch->GetName(), b_yang);
		ch->ChatPacket(CHAT_TYPE_INFO,  EnglishLC[18], b_yang, tch->GetName());
		#else
		tch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s size %d yangg gonderdi."), ch->GetName(), b_yang);
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s karakterine %d yangg gonderdiniz."), tch->GetName(), b_yang);
		#endif
	}
	
	if (b_won > 0)
	{
		tch->PointChange(POINT_CHEQUE, +b_won, true);
		ch->SetQuestFlag(WONN(), won_bank(ch)-b_won);
		#ifdef ENABLE_LC_ENGLISH
		tch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[19], ch->GetName(), b_won);
		ch->ChatPacket(CHAT_TYPE_INFO,  EnglishLC[20], b_won, tch->GetName());	
		#else
		tch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s size %d wonn gonderdi."), ch->GetName(), b_won);
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s karakterine %d wonn gonderdiniz."), tch->GetName(), b_won);
		#endif
	}
	
	if (b_coins > 0)
	{
		std::auto_ptr<SQLMsg> msg(DBManager::instance().DirectQuery("UPDATE account.account SET coins = coins + '%ld' WHERE id = '%d'", b_coins, tch->GetDesc()->GetAccountTable().id));
		ch->SetQuestFlag(COINSS(), coins_bank(ch)-b_coins);
		#ifdef ENABLE_LC_ENGLISH
		tch->ChatPacket(CHAT_TYPE_INFO, EnglishLC[21], ch->GetName(), b_coins);
		ch->ChatPacket(CHAT_TYPE_INFO,  EnglishLC[22], b_coins, tch->GetName());
		#else
		tch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s size %d epp gonderdi."), ch->GetName(), b_coins);
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s karakterine %d epp gonderdiniz."), tch->GetName(), b_coins);
		#endif
	}
	
	Start(ch, true);
	Start(tch, true);
	HoldALog(ch, "Send", tch);
}
void CBankManager::HoldALog(LPCHARACTER ch, const char* type, LPCHARACTER tch)
{
	char * alog = (char*) malloc(sizeof(*alog));
	if (tch == NULL || !tch)
	{
		snprintf(alog, 1024, "INSERT INTO log.bank_log (Name, ID, Type, ip, TargetName, TargetID, Targetip, time) VALUES('%s', '%d', '%s', '%s', '%s', '%d', '%s', NOW())", 
		ch->GetName(), ch->GetPlayerID(), type, ch->GetDesc()->GetHostName(), "Empty", 0, "Empty");
	}
	else
	{
		snprintf(alog, 1024, "INSERT INTO log.bank_log (Name, ID, Type, ip, TargetName, TargetID, Targetip, time) VALUES('%s', '%d', '%s', '%s', '%s', '%d', '%s', NOW())", 
		ch->GetName(), ch->GetPlayerID(), type, ch->GetDesc()->GetHostName(), tch->GetName(), tch->GetPlayerID(), tch->GetDesc()->GetHostName());
	}
	SQLMsg * msg = DBManager::instance().DirectQuery(alog);
}