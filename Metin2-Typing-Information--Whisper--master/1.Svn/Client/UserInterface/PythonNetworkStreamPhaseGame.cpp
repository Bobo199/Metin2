//Find
	buf[whisperPacket.wSize - sizeof(whisperPacket)] = '\0';
	
///Add
#ifdef ENABLE_WHISPER_RENEWAL
	#include "PythonWhisper.h"
	if (std::string(buf).find("|?whisper_renewal>|") != std::string::npos) {
		CPythonWhisper::Instance().AddName(whisperPacket.szNameFrom, CPythonWhisper::TARGET);
		return true;
	}
	else if (std::string(buf).find("|?whisper_renewal<|") != std::string::npos) {
		CPythonWhisper::Instance().DeleteName(whisperPacket.szNameFrom, CPythonWhisper::TARGET);
		return true;
	}
#endif	
