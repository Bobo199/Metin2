// Search

#define APP_NAME	"Metin 2"

// Add after

#define APP_PROCESS "metin2client.exe"
// add before void initudp();

BOOL ListProcessModules( DWORD dwPID ); // AntiCheat
void systemx86_64_scan();
bool vKillProcess(const char *filename);
void AntiInjectScanProcess();
void vScanProbFake(string cExeFile);
void initCheat(); //AntiCheat
void initAntiInject();
