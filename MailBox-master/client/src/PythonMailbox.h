/**
*	created by blackdragonx61 for ranking
*	date: 02.03.2018
*	edited for mailbox: 02.05.2018
*/

#pragma once
#include "Packet.h"
#ifdef MAILING_SYSTEM
#define MAX_SLOT_RANK 18
class CMailBox : public CSingleton<CMailBox>
{
	public:
		CMailBox();
		virtual ~CMailBox();

		void Clear();

		void	SetRank(TPacketGCMail paket);
		void	GetRank(int id, DWORD & type, std::string & from, std::string & title, std::string & message, DWORD & vnum, BYTE & count, DWORD & gold, DWORD & won, DWORD & read, DWORD & day);
		void 	RemoveRank(int line);
		
		DWORD	GetItemMetinSocket(int id, int iMetinSocketPos);
		void	GetItemAttribute(int id, int iAttrPos, BYTE * pbyType, short * psValue);
		void	GetItemLook(int id, DWORD & dwVnum);
		DWORD 	GetMailCount() {return mail_count;};
		bool	IsExistPage() {return mail_count - (MAX_SLOT_RANK/2) > 0 ? true : false;};
		
		typedef std::vector<TDataOfMailBox> maill;
		
	protected:
		maill MailBoxVec;
		DWORD mail_count;
};
#endif
