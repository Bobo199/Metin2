// Add

void initCheat()
{
  HANDLE hProcessSnap;
  HANDLE hProcess;
  PROCESSENTRY32 pe32;
  DWORD dwPriorityClass;
  string cExeFile, sVocable, sConsonant;
  string __VOCABLES = "aAbBeEiIoOuUyY";
  string __Consonants = "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";
  //string __VOCABLES[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
  //string __Consontants[] = { 'b', 'B', 'c', 'C', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K'
  //	, 'l', 'L', 'm', 'M', 'n', 'N', 'ñ', 'Ñ', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'v', 'V', 'w', 'W', 'x', 'X' 
  //	, 'y', 'Y', 'z', 'Z'};
  int iCountFake = 0;

  hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if( hProcessSnap == INVALID_HANDLE_VALUE )
  {
    TraceError("CreateToolhelp32Snapshot (of processes)");
  }

  pe32.dwSize = sizeof( PROCESSENTRY32 );

  if( !Process32First( hProcessSnap, &pe32 ) )
  {
    CloseHandle( hProcessSnap );          // clean the snapshot object
  }
  
  do
  {
	if (strcmp(pe32.szExeFile, "cheatengine-x86_64.exe") == 0)
	{
		killProcessByName(pe32.szExeFile);
		killProcessByName("metin2client.exe");
	}
	else if (strcmp(pe32.szExeFile, "cheatengine-x86.exe") == 0)
	{
		killProcessByName(pe32.szExeFile);
		killProcessByName("metin2client.exe");
	}
	else if (strcmp(pe32.szExeFile, "cheatengine-x64.exe") == 0)
	{
		killProcessByName(pe32.szExeFile);
		killProcessByName("metin2client.exe");
	}
	else if (strcmp(pe32.szExeFile, "cheatenginex86_64.exe") == 0)
	{
		killProcessByName(pe32.szExeFile);
		killProcessByName("metin2client.exe");
	}
	else if (strcmp(pe32.szExeFile, "cheatengine.exe") == 0)
	{
		killProcessByName(pe32.szExeFile);
		killProcessByName("metin2client.exe");
	}

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
    bListProcModules( pe32.th32ProcessID );

  } while( Process32Next( hProcessSnap, &pe32 ) );

  CloseHandle( hProcessSnap );
}

BOOL bListProcModules( DWORD dwPID )
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
	if (strcmp(me32.szModule, "Python_Loader_2.7.dll") == 0)
	{
		killProcessByName(me32.szModule);
		killProcessByName("metin2client.exe");
	}
	else if (strcmp(me32.szModule, "Injector.exe") == 0)
	{
		killProcessByName(me32.szModule);
		killProcessByName("metin2client.exe");
	}
	else if (strcmp(me32.szModule, "Extreme_Injector_v3.exe") == 0)
	{
		killProcessByName(me32.szModule);
		killProcessByName("metin2client.exe");
	}
	//TraceError("MODULE NAME_PORCARACTER:     %s \n",   cModule_name );
    //TraceError("    Executable     = %s \n",     me32.szExePath );
  } while( Module32Next( hModuleSnap, &me32 ) );

  CloseHandle( hModuleSnap );
  return( TRUE );
}

void vAntiCheat()
{
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	string cExeFile, sVocable, sConsonant;
	string __VOCABLES = "aAbBeEiIoOuU";
	string __Consonants = "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";
	//string __VOCABLES[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
	//string __Consontants[] = { 'b', 'B', 'c', 'C', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K'
	//	, 'l', 'L', 'm', 'M', 'n', 'N', 'ñ', 'Ñ', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'v', 'V', 'w', 'W', 'x', 'X' 
	//	, 'y', 'Y', 'z', 'Z'};
 	int iCountFake = 0;
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
		if (strcmp(pe32.szExeFile, "cheatengine-x86_64.exe") == 0)
		{
			killProcessByName(pe32.szExeFile);
			killProcessByName("metin2client.exe");
		}
		else if (strcmp(pe32.szExeFile, "cheatengine-x86.exe") == 0)
		{
			killProcessByName(pe32.szExeFile);
			killProcessByName("metin2client.exe");
		}
		else if (strcmp(pe32.szExeFile, "cheatengine-x64.exe") == 0)
		{
			killProcessByName(pe32.szExeFile);
			killProcessByName("metin2client.exe");
		}
		else if (strcmp(pe32.szExeFile, "cheatenginex86_64.exe") == 0)
		{
			killProcessByName(pe32.szExeFile);
			killProcessByName("metin2client.exe");
		}
		else if (strcmp(pe32.szExeFile, "cheatengine.exe") == 0)
		{
			killProcessByName(pe32.szExeFile);
			killProcessByName("metin2client.exe");
		}
		else if (strcmp(pe32.szExeFile, "Python_Loader_2.7.dll") == 0)
		{
			killProcessByName(pe32.szExeFile);
			killProcessByName("metin2client.exe");
		}
		else if (strcmp(pe32.szExeFile, "Injector.exe") == 0)
		{
			killProcessByName(pe32.szExeFile);
			killProcessByName("metin2client.exe");
		}
		else if (strcmp(pe32.szExeFile, "Extreme_Injector_v3.exe") == 0)
		{
			killProcessByName(pe32.szExeFile);
			killProcessByName("metin2client.exe");
		}

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
		bListProcModules(pe32.th32ProcessID);

	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
}

void initThreadPack(){
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(vScan_thread), NULL, 0, 0);
}

void vScan_thread(){
	Sleep(2000);
again:
	vAntiCheat();
	vScanForPy();
	Sleep(2000);
	goto again;
}

bool bKillProc(const char *filename)
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

#define BUFSIZE MAX_PATH

void vScanForPy() {
	//Part Get Current Directory
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	//Part Scan Next Process of the Win Api
	string dir;
	dir = string(buffer).substr(0, pos);
	sAll_Files_Names(dir);
	sAll_Files_Names(dir + "/\\BGM");
	sAll_Files_Names(dir + "/\\lib");
	sAll_Files_Names(dir + "/\\mark");
	sAll_Files_Names(dir + "/\\miles");
	sAll_Files_Names(dir + "/\\pack");
	sAll_Files_Names(dir + "/\\screenshot");
	sAll_Files_Names(dir + "/\\shops");
	sAll_Files_Names(dir + "/\\svside");
	sAll_Files_Names(dir + "/\\temp");
	sAll_Files_Names(dir + "/\\upload");

}

vector<string> sAll_Files_Names(string folder)
{
	vector<string> names;
	string search_path = folder + "/*.py";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				TraceError("Hack Python Detect -> %s Remove the File",fd.cFileName);
				killProcessByName("metin2client.exe");
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}
