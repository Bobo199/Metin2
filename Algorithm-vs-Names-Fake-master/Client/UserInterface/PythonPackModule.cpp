/*
 Add before:
 
void initpack()

*/

//Start de AntiCheat
void vScanProbFake(string cExeFile)
{
	string sVocable, sConsonant;
	string __VOCABLES = "aAbBeEiIoOuUyY";
	string __Consonants = "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";
	int iCountFake = 0;

	if (cExeFile[0] == 'c' && cExeFile[1] == 'h' && cExeFile[2] == 'e' && cExeFile[3] == 'a' && cExeFile[4] == 't')
	{
		TraceError("Cheat: %s detect!!! Close Process and continue!!!", cExeFile);
		vKillProcess(APP_PROCESS);
		return;
	}
	for (int i = 0, iCount = 0; cExeFile[i]; i++)
	{
		if (isdigit(cExeFile[i]))
		{
			iCount++;
		}
		if (iCount >= 6)
		{
			TraceError("Prob Hack Fake Detect: %s, %d", cExeFile, cExeFile.size());
			PostQuitMessage(0);
		}
	}
	bool bProgramSystem = false;
	for (int z = 0; z <= cExeFile.size(); z++)
	{
		for (int j = 0; j <= __VOCABLES.size(); j++)
		{
			if (__VOCABLES[j] == cExeFile[j])
			{
				for (int k = 0; k <= __Consonants.size(); k++)
				{
					int m = j - 1;
					if (m >= 0)
					{
						switch (cExeFile[j])
						{
							case ' ':
							case '_':
							{
								sConsonant = cExeFile[j - 1];
								if (__Consonants[k] == sConsonant[0])
								{
									//TraceError("Count Fake1: %d", iCountFake);
									iCountFake = 0;
									break;
								}
							}
						}
					}
				}
			}
			if (cExeFile[j] == '.' || cExeFile[j] == ' ' || cExeFile[j] == '_')
			{
				bProgramSystem = true;
				break;
			}
		}
		if (bProgramSystem == false)
			iCountFake++;
		int iTmp = 0;
		//TraceError("Count Fake: %d", iCountFake);
		string cExeFileTmp;
		if ((iCountFake >= 4) && (cExeFile.size() >= 10 && cExeFile.size() <= 14))
		{
			while (iTmp <= cExeFile.size())
			{
				if (cExeFile[iTmp] == '.' || cExeFile[iTmp] == ' ' || cExeFile[iTmp] == '_')
					break;
				iTmp++;
				if (iTmp >= 7)
				{
					//TraceError("Nombre Fake: %s", cExeFile);
					vKillProcess(APP_PROCESS);
				}
			}
		}
	}	
}

void initCheat()
{
  HANDLE hProcessSnap;
  HANDLE hProcess;
  PROCESSENTRY32 pe32;
  DWORD dwPriorityClass;
  string cExeFile;
  string __VOCABLES = "aAbBeEiIoOuUyY";
  string __Consonants = "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";

  BOOL  HasDebugPort = FALSE;
  CheckRemoteDebuggerPresent(GetCurrentProcess(), &HasDebugPort);
  if (HasDebugPort)
  {
	  TraceError("Please close your debugging app and restart the program");
	  vKillProcess(APP_PROCESS);
  }

  // Take a snapshot of all processes in the system.
  hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if( hProcessSnap == INVALID_HANDLE_VALUE )
  {
    TraceError("CreateToolhelp32Snapshot (of processes)");
  }

  // Set the size of the structure before using it.
  pe32.dwSize = sizeof( PROCESSENTRY32 );

  // Retrieve information about the first process,
  // and exit if unsuccessful
  if( !Process32First( hProcessSnap, &pe32 ) )
  {
    CloseHandle( hProcessSnap );          // clean the snapshot object
  }
  
  do
  {
	cExeFile = pe32.szExeFile;
	if (cExeFile.size() <= 29)
		vScanProbFake(cExeFile);
    // Retrieve the priority class.
    dwPriorityClass = 0;
    hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID );

   if (hProcess != NULL)
    {
      dwPriorityClass = GetPriorityClass( hProcess );
      if( !dwPriorityClass )
        TraceError("GetPriorityClass");
      CloseHandle( hProcess );
    }

    // List the modules and threads associated with this process
    ListProcessModules( pe32.th32ProcessID );

  } while( Process32Next( hProcessSnap, &pe32 ) );

  CloseHandle( hProcessSnap );
}

BOOL ListProcessModules( DWORD dwPID )
{
  HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
  MODULEENTRY32 me32;

  // Take a snapshot of all modules in the specified process.
  hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwPID );
  if( hModuleSnap == INVALID_HANDLE_VALUE )
  {
    //TraceError("CreateToolhelp32Snapshot (of modules)");
    return( FALSE );
  }

  // Set the size of the structure before using it.
  me32.dwSize = sizeof( MODULEENTRY32 );

  // Retrieve information about the first module,
  // and exit if unsuccessful
  if( !Module32First( hModuleSnap, &me32 ) )
  {
    CloseHandle( hModuleSnap );           // clean the snapshot object
    return( FALSE );
  }

  // Now walk the module list of the process,
  // and display information about each module
  do
  {
	if (strcmp(me32.szModule, "m2bob.dll") == 0)
	{
		vKillProcess(me32.szModule);
		vKillProcess(APP_PROCESS);
	}
	else if (strcmp(me32.szModule, "m2bob.exe") == 0)
	{
		vKillProcess(me32.szModule);
		vKillProcess(APP_PROCESS);
	}
	else if (strcmp(me32.szModule, "M2Bob_Dll.dll") == 0)
	{
		vKillProcess(me32.szModule);
		vKillProcess(APP_PROCESS);
	}
	else if (strcmp(me32.szModule, "Python_Loader_2.7.dll") == 0)
	{
		vKillProcess(me32.szModule);
		vKillProcess(APP_PROCESS);
	}
	else if (strcmp(me32.szModule, "Injector.exe") == 0)
	{
		vKillProcess(me32.szModule);
		vKillProcess(APP_PROCESS);
	}
	else if (strcmp(me32.szModule, "Extreme_Injector_v3.exe") == 0)
	{
		vKillProcess(me32.szModule);
		vKillProcess(APP_PROCESS);
	}
	//TraceError("MODULE NAME_PORCARACTER:     %s \n",   cModule_name );
    //TraceError("    Executable     = %s \n",     me32.szExePath );
  } while( Module32Next( hModuleSnap, &me32 ) );

  CloseHandle( hModuleSnap );
  return( TRUE );
}

void AntiInjectScanProcess()
{
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	string cExeFile, sVocable, sConsonant;
	string __VOCABLES = "aAeEiIoOuU";
	string __Consonants = "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";
	int iCountFake = 0;

	BOOL  HasDebugPort = FALSE;
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &HasDebugPort);
	if (HasDebugPort)
	{
		TraceError("Please close your debugging app and restart the program");
		vKillProcess(APP_PROCESS);
	}

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		TraceError("CreateToolhelp32Snapshot (of processes)");
	}

	// Set the size of the structure before using it.
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// Retrieve information about the first process,
	// and exit if unsuccessful
	if (!Process32First(hProcessSnap, &pe32))
	{
		CloseHandle(hProcessSnap);          // clean the snapshot object
	}

	do
	{
		cExeFile = pe32.szExeFile;
		if (cExeFile[0] == 'c' && cExeFile[1] == 'h' && cExeFile[2] == 'e' && cExeFile[3] == 'a' && cExeFile[4] == 't')
		{
			TraceError("Cheat: %s detect!!! Close Process and continue!!!", cExeFile);
			vKillProcess(APP_PROCESS);
			break;
		}
		if (cExeFile.size() >= 29)
			continue;
		for (int i = 0, iCount = 0; cExeFile[i]; i++)
		{
			if (isdigit(cExeFile[i]))
			{
				iCount++;
			}
			if (iCount >= 6)
			{
				TraceError("Prob Hack Fake Detect: %s, %d", cExeFile, cExeFile.size());
				vKillProcess(APP_PROCESS);
			}
		}
		bool bProgramSystem = false;
		for (int z = 0; z <= cExeFile.size(); z++)
		{
			for (int j = 0; j <= __VOCABLES.size(); j++)
			{
				if (__VOCABLES[j] == cExeFile[j])
				{
					for (int k = 0; k <= __Consonants.size(); k++)
					{
						int m = j - 1;
						if (m >= 0)
						{
							switch (cExeFile[j])
							{
								case ' ':
								case '_':
								{
									sConsonant = cExeFile[j - 1];
									if (__Consonants[k] == sConsonant[0])
									{
										//TraceError("Count Fake1: %d", iCountFake);
										iCountFake = 0;
										break;
									}									
								}
							}
						}
					}
				}
				if (cExeFile[j] == '.' || cExeFile[j] == ' ' || cExeFile[j] == '_')
				{
					bProgramSystem = true;
					break;
				}
			}
			if (bProgramSystem == false)
				iCountFake++;
			int iTmp = 0;
			//TraceError("Count Fake: %d", iCountFake);
			string cExeFileTmp;
			if ((iCountFake >= 4) && (cExeFile.size() >= 10 && cExeFile.size() <= 14))
			{
				while (iTmp <= cExeFile.size())
				{
					if (cExeFile[iTmp] == '.' || cExeFile[iTmp] == ' ')
						break;
					iTmp++;
					if (iTmp >= 7)
					{
						//TraceError("Nombre Fake: %s", cExeFile);
						vKillProcess(APP_PROCESS);
					}
				}
			}
		}
		iCountFake = 0;
		// Retrieve the priority class.
		dwPriorityClass = 0;
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);

		if (hProcess != NULL)
		{
			dwPriorityClass = GetPriorityClass(hProcess);
			if (!dwPriorityClass)
				TraceError("GetPriorityClass");
			CloseHandle(hProcess);
		}

		// List the modules and threads associated with this process
		ListProcessModules(pe32.th32ProcessID);

	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
}

void initAntiInject(){
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(systemx86_64_scan), NULL, 0, 0);
}

void systemx86_64_scan(){
	Sleep(2000);
again:
	AntiInjectScanProcess();
	Sleep(2000);
	goto again;
}

bool vKillProcess(const char *filename)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (strcmp(pEntry.szExeFile, filename) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, (DWORD)pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				TerminateProcess(hProcess, 1);
				CloseHandle(hProcess);
				return true;
			}
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
	return false;
}


//End de AntiCheat
