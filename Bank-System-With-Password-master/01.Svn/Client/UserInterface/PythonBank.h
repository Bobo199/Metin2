#pragma once

#ifdef __BANK_SYSTEM__
class CBankManager : public CSingleton<CBankManager>
{	
	public:
		CBankManager();
		virtual ~CBankManager();
		
		void	Reset();
		void	SetFields(DWORD yang, DWORD coins, DWORD won, DWORD nw_coins);
		void	GetFields(DWORD & yang, DWORD & coins, DWORD & won, DWORD & nw_coins);
		int m_change_password() { return change_password; }
		void set_change_password(int a) { change_password = a; }
	
	protected:
		BYTE change_password; // is opened
		DWORD bl_yang;
		DWORD bl_coins;
		DWORD bl_won;
		DWORD bl_nw_coins;
};
#endif
