// Search:

#include "GameType.h"
extern DWORD __DEFAULT_CODE_PAGE__;
#define APP_NAME	"Metin 2"

// Add after or before:

#define APP_PROCESS "metin2client.exe" // Put the name of your binary between the quotes. Example: "mybinary.exe"

//Search:

void initudp();

//Add before:

void AntiDebugScanProcess();
bool vKillProcess(const char *filename);
void initThreadAntiDebug();
void vScan_AntiDebug_thread();
