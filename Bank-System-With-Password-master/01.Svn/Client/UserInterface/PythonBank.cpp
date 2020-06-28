#include "StdAfx.h"

#ifdef __BANK_SYSTEM__
#include "PythonBank.h"
#include "PythonNetworkStream.h"
#include "InstanceBase.h"
#include "pythoncharactermanager.h"

CBankManager::CBankManager()
{
	Reset();
}

CBankManager::~CBankManager()
{
	Reset();
}

void CBankManager::Reset()
{
	bl_yang = 0;
	bl_coins = 0;
	bl_won = 0;
	bl_nw_coins = 0;
	change_password = 0;
}

void CBankManager::SetFields(DWORD yang, DWORD coins, DWORD won, DWORD nw_coins)
{	
	Reset();
	
	if (yang <= 0)
		yang = 0;
	
	if (coins <= 0)
		coins = 0;
	
	if (won <= 0)
		won = 0;
	
	if (nw_coins <= 0)
		nw_coins = 0;
	
	bl_yang = yang;
	bl_coins = coins;
	bl_won = won;
	bl_nw_coins = nw_coins;
}

void CBankManager::GetFields(DWORD & yang, DWORD & coins, DWORD & won, DWORD & nw_coins)
{
	yang = bl_yang;
	coins = bl_coins;
	won = bl_won;
	nw_coins = bl_nw_coins;
}

PyObject* SendBankStartPacket(PyObject* poSelf, PyObject* poArgs)
{
	char* pass;
	if (!PyTuple_GetString(poArgs, 0, &pass))
		return Py_BuildException();
	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendBankStartPacket(pass);
	return Py_BuildNone();
}

PyObject* SendBankChangePassword(PyObject* poSelf, PyObject* poArgs)
{
	char* old_pass;
	if (!PyTuple_GetString(poArgs, 0, &old_pass))
		return Py_BuildException();
	char* new_pass;
	if (!PyTuple_GetString(poArgs, 1, &new_pass))
		return Py_BuildException();
	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendBankChangePassword(old_pass, new_pass);
	return Py_BuildNone();
}

PyObject* SendBankClosePacket(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendBankClosePacket();
	return Py_BuildNone();
}

PyObject* SendBankAddPacket(PyObject* poSelf, PyObject* poArgs)
{
	int yang;
	if (!PyTuple_GetInteger(poArgs, 0, &yang))
		return Py_BuildException();
	int coins;
	if (!PyTuple_GetInteger(poArgs, 1, &coins))
		return Py_BuildException();
	int won;
	if (!PyTuple_GetInteger(poArgs, 2, &won))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendBankAddPacket(yang, coins, won);
	return Py_BuildNone();
}

PyObject* OpenChangePassword(PyObject* poSelf, PyObject* poArgs)
{
	int password;
	if (!PyTuple_GetInteger(poArgs, 0, &password))
		return Py_BuildException();

	CBankManager::Instance().set_change_password(password);
	return Py_BuildNone();
}

PyObject* GetChangePassword(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CBankManager::Instance().m_change_password());
}

PyObject* SendBankWithDrawPacket(PyObject* poSelf, PyObject* poArgs)
{
	int yang;
	if (!PyTuple_GetInteger(poArgs, 0, &yang))
		return Py_BuildException();
	int coins;
	if (!PyTuple_GetInteger(poArgs, 1, &coins))
		return Py_BuildException();
	int won;
	if (!PyTuple_GetInteger(poArgs, 2, &won))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendBankWithDrawPacket(yang, coins, won);
	return Py_BuildNone();
}

PyObject* SendBankSendPacket(PyObject* poSelf, PyObject* poArgs)
{
	int vid;
	if (!PyTuple_GetInteger(poArgs, 0, &vid))
		return Py_BuildException();
	int yang;
	if (!PyTuple_GetInteger(poArgs, 1, &yang))
		return Py_BuildException();
	int coins;
	if (!PyTuple_GetInteger(poArgs, 2, &coins))
		return Py_BuildException();
	int won;
	if (!PyTuple_GetInteger(poArgs, 3, &won))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendBankSendPacket(vid, yang, coins, won);
	return Py_BuildNone();
}

PyObject * GetBankFields(PyObject * poSelf, PyObject * poArgs)
{
	DWORD yang, coins, won, nw_coins;
	CBankManager::Instance().GetFields(yang, coins, won, nw_coins);
	return Py_BuildValue("iiii", yang, coins, won, nw_coins);
}

void initBank()
{
	static PyMethodDef bl_fnctns[] = {
		{ "SendStartPacket",	SendBankStartPacket,		METH_VARARGS },
		{ "SendClosePacket",	SendBankClosePacket,		METH_VARARGS },
		{ "SendAddPacket",		SendBankAddPacket,			METH_VARARGS },
		{ "SendWithDrawPacket",	SendBankWithDrawPacket,		METH_VARARGS },
		{ "SendSendPacket",		SendBankSendPacket,			METH_VARARGS },
		{ "GetFields",			GetBankFields,				METH_VARARGS },
		{ "SendChangePassword",	SendBankChangePassword,		METH_VARARGS },
		{ "OpenChangePassword",	OpenChangePassword,			METH_VARARGS },
		{ "GetChangePassword",	GetChangePassword,			METH_VARARGS },
		{NULL, NULL, NULL},
	};
	
	PyObject* pModule = Py_InitModule("bank", bl_fnctns);
	PyModule_AddIntConstant(pModule, "LIMIT_RANGE", 1000);
}
#endif