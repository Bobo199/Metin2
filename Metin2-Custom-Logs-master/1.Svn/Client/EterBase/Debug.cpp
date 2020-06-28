//Find
HWND g_PopupHwnd = NULL;

///Add
#if defined(CUSTOM_LOGS)
#include <memory>
#include <chrono>
#include <time.h>
#include <filesystem>
class CustomLogFile : public CSingleton<CustomLogFile>
{
	public:
		CustomLogFile(const std::string& path) { 
			if (!filesystem::is_directory(path) || !filesystem::exists(path))
				if (!filesystem::create_directory(path))
					return;
			for (const std::string& v : { "ITEM_ERROR.txt", "MAP_ERROR.txt" })
				m_fp.emplace_back(unique_ptr<std::FILE, decltype(&fclose)>(fopen((path + "/" + v).c_str(), "a"), &fclose));		
		}
		virtual ~CustomLogFile() {m_fp.clear();}
		void Write(const char* c_pszMsg, BYTE Type) {
			if (Type >= m_fp.size() || !m_fp.at(Type).get())
				return;
			const __time64_t ct = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			char buffer[80];
			strftime(buffer, sizeof(buffer), "%d.%m.%Y-%H:%M:%S", localtime(&ct));
			fprintf(m_fp.at(Type).get(), "%s :: %s\n", buffer , c_pszMsg);
			fflush(m_fp.at(Type).get());
		}
	protected:
		std::vector <std::unique_ptr<std::FILE, decltype(&fclose)>> m_fp;
};
#endif

//Find
static CLogFile gs_logfile;

///Add
#if defined(CUSTOM_LOGS)
static CustomLogFile JustForInit("logs");
void LogFileWithType(BYTE Type, const char * c_szMessage, ...)
{
	va_list args;
	va_start(args, c_szMessage);
	char szBuf[DEBUG_STRING_MAX_LEN+1];
	_vsnprintf(szBuf, sizeof(szBuf), c_szMessage, args);
	va_end(args);
	CustomLogFile::Instance().Write(szBuf, Type);
}
#endif
