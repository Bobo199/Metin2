// Add on any file in your client

void AntiDebugScanProcess(){
	//
	//Start Variables
	//
	
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	string cExeFile;
	BOOL  HasDebugPort = FALSE;
	//
	//End Variables
	//
	
	//
	//Check Debugger Port
	//
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &HasDebugPort);
	if (HasDebugPort)
	{
		TraceError("Please close your debugging app and restart the program");
		vKillProcess(APP_PROCESS);
	}
	//
	//End Debugger Port
	//
	
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
	//
	//Check Debugger Engine
	//
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
	//
	// End Check Debugger Engine
	//
	CloseHandle(hProcessSnap);
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

void initThreadAntiDebug(){
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(vScan_AntiDebug_thread), NULL, 0, 0);
}

void vScan_AntiDebug_thread(){
	Sleep(2000);
again:
	AntiDebugScanProcess();
	Sleep(2000);
	goto again;
}
