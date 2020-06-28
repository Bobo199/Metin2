//Find
PyObject* netLogOutGame(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(VOICE_CHAT)
#include <array>
const std::list<std::string> voicechatmessage
{
	"-Don't touch this line-",
	"Go go go! : 1",
	"Fuck you! : 2",
	"Mission Failed! : 3",
	"Okey : 4",
	"Negative! : 5",
	"Follow me. : 6",
	"Close : Z, X",
};
PyObject* netSendVoiceChatPacket(PyObject* poSelf, PyObject* poArgs)
{
	std::array<int, 2> val;
	for (auto i = 0; i < val.size(); i++)
		if (!PyTuple_GetInteger(poArgs, i, &val[i]))
			return Py_BuildException();
	CPythonNetworkStream::Instance().SendVoiceChatPacket(val[0],val[1]);
	return Py_BuildNone();
}
PyObject* netGetVoiceChatList(PyObject* poSelf, PyObject* poArgs)
{
	PyObject * _VoiceChat = PyTuple_New(voicechatmessage.size());
	int i = 0;
	for (const auto & v : voicechatmessage) 
		PyTuple_SetItem(_VoiceChat, i++, Py_BuildValue("s", v.c_str()));
	return _VoiceChat;
}
#endif

//Find
		{ "SendChatPacket",						netSendChatPacket,						METH_VARARGS },
		
///Add
#if defined(VOICE_CHAT)
		{ "GetVoiceChatList",					netGetVoiceChatList,					METH_VARARGS },
		{ "SendVoiceChatPacket",				netSendVoiceChatPacket,					METH_VARARGS },
#endif