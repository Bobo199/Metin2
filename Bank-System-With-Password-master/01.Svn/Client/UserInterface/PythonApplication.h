//Find
#include "MovieMan.h"

///Add
#ifdef __BANK_SYSTEM__
#include "PythonBank.h"
#endif

//Find
		CPythonMessenger			m_pyManager;
		
///Add
#ifdef __BANK_SYSTEM__
		CBankManager				m_pyBank;
#endif