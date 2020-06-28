//Find
#include "DragonSoul.h"

///Add

#ifdef __BANK_SYSTEM__
#include "NewBankSystem.h"
#endif

//Find
void CInputMain::Fishing(LPCHARACTER ch, const char* c_pData)
{
	TPacketCGFishing* p = (TPacketCGFishing*)c_pData;
	ch->SetRotation(p->dir * 5);
	ch->fishing();
	return;
}

///Add
#ifdef __BANK_SYSTEM__
void CInputMain::Bank(LPCHARACTER ch, const char * data)
{
	struct command_bank * pinfo = (struct command_bank *) data;
	char password[100], password2[100];
	sys_log(0, "CInputMain()::Bank()  SubHeader %d ", pinfo->subheader);

	switch (pinfo->subheader)
	{
		case BANK_SUBHEADER_CG_START:
			strlcpy(password, pinfo->pass, sizeof(password));
			CBankManager::instance().ReqPass(ch, password);
			// CBankManager::instance().Start(ch, false);
		break;
		
		case BANK_SUBHEADER_CG_CLOSE:
			CBankManager::instance().Close(ch);
		break;

		case BANK_SUBHEADER_CG_ADD:
			CBankManager::instance().Add(ch, pinfo->arg1, pinfo->arg2, pinfo->arg3);
		break;	
		
		case BANK_SUBHEADER_CG_WITHDRAW:
			CBankManager::instance().WithDraw(ch, pinfo->arg1, pinfo->arg2, pinfo->arg3);
		break;
		
		case BANK_SUBHEADER_CG_SEND:
			strlcpy(password, pinfo->pass, sizeof(password));
			CBankManager::instance().Send(ch, password, pinfo->arg2, pinfo->arg3, pinfo->arg4);
		break;
		
		case BANK_SUBHEADER_CG_CHANGE_PASSWORD:
			strlcpy(password, pinfo->pass, sizeof(password));
			strlcpy(password2, pinfo->pass2, sizeof(password2));
			CBankManager::instance().ChangeBankPassword(ch, password, password2);
		break;
	}
}
#endif

//Find
		case HEADER_CG_EXCHANGE:
			if (!ch->IsObserverMode())
				Exchange(ch, c_pData);
			break;
			
///Add
		#ifdef __BANK_SYSTEM__
		case HEADER_CG_BANK:
			if (!ch->IsObserverMode())
				Bank(ch, c_pData);
			break;
		#endif