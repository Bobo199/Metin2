/*
	Author: Blackdragonx61
	Date:	01.05.2018
*/
#include "StdAfx.h"
#include "Packet.h"
#include "PythonNetworkStream.h"
#include "PythonApplication.h"
#include "PythonNetworkStream.h"
#include "InstanceBase.h"
#include "pythoncharactermanager.h"
#include "PythonMailbox.h"
#ifdef MAILING_SYSTEM

CMailBox::CMailBox()
{
	Clear();
}

CMailBox::~CMailBox()
{
	Clear();
}

void CMailBox::Clear()
{
	MailBoxVec.resize(MAX_SLOT_RANK);
	MailBoxVec.clear();
}

void CMailBox::SetRank(TPacketGCMail paket)
{
	Clear();
	mail_count = paket.m_count;
	for (int i = 0; i < GetMailCount(); i++)
		MailBoxVec.push_back(paket.line[i]);
}

void CMailBox::GetRank(int id, DWORD & type, std::string & from, std::string & title, std::string & message, DWORD & vnum, BYTE & count, DWORD & gold, DWORD & won, DWORD & read, DWORD & day)
{
	type = MailBoxVec[id].type;
	title = MailBoxVec[id].title;
	message = MailBoxVec[id].message;
	from = MailBoxVec[id].from;
	gold = MailBoxVec[id].gold;
	won = MailBoxVec[id].won;
	read = MailBoxVec[id].read;
	vnum = MailBoxVec[id].vnum;
	count = MailBoxVec[id].count;
	day = MailBoxVec[id].day;
}

DWORD CMailBox::GetItemMetinSocket(int id, int iMetinSocketPos)
{
	return MailBoxVec[id].alSockets[iMetinSocketPos];
}

void CMailBox::GetItemAttribute(int id, int iAttrPos, BYTE * pbyType, short * psValue)
{
	*pbyType = MailBoxVec[id].aAttr[iAttrPos].bType;
	*psValue = MailBoxVec[id].aAttr[iAttrPos].sValue;
}
#ifdef ENABLE_CHANGE_LOOK_SYSTEM
void CMailBox::GetItemLook(int id, DWORD & dwVnum)
{
	dwVnum = MailBoxVec[id].dwVnum;
}
#endif
PyObject * GetRank(PyObject * poSelf, PyObject * poArgs)
{
	int line;
	if (!PyTuple_GetInteger(poArgs, 0, &line))
		return Py_BuildException();
	DWORD type, vnum, gold, won, read, day;
	BYTE count;
	std::string from, title, message;
	CMailBox::Instance().GetRank(line, type, from, title, message, vnum, count, gold, won, read, day);
	return Py_BuildValue("isssiiiiii", type, from.c_str(), title.c_str(), message.c_str(), vnum, count, gold, won, read, day);
}

PyObject * AcceptRank(PyObject * poSelf, PyObject * poArgs)
{
	int line;
	if (!PyTuple_GetInteger(poArgs, 0, &line))
		return Py_BuildException();
	
	CPythonNetworkStream& asd = CPythonNetworkStream::Instance();
	asd.SendMailData(MAIL_SUBHEADER_ACCEPT_MAIL, "", "", "", line);
	return Py_BuildNone();
}

PyObject * SetRead(PyObject * poSelf, PyObject * poArgs)
{
	int line;
	if (!PyTuple_GetInteger(poArgs, 0, &line))
		return Py_BuildException();
	
	CPythonNetworkStream& asd = CPythonNetworkStream::Instance();
	asd.SendMailData(MAIL_SUBHEADER_READ, "", "", "", line);
	return Py_BuildNone();
}

PyObject * RemoveRank(PyObject * poSelf, PyObject * poArgs)
{
	int line;
	if (!PyTuple_GetInteger(poArgs, 0, &line))
		return Py_BuildException();
	
	CPythonNetworkStream& asd = CPythonNetworkStream::Instance();
	asd.SendMailData(MAIL_SUBHEADER_DELETE_MAIL, "", "", "", line);
	return Py_BuildNone();
}

PyObject * RefreshMails(PyObject * poSelf, PyObject * poArgs)
{
	CPythonNetworkStream::Instance().SendMailData(MAIL_SUBHEADER_RELOAD);
	return Py_BuildNone();
}

PyObject* SendMail(PyObject* poSelf, PyObject* poArgs)
{
	int subheader;
	if (!PyTuple_GetInteger(poArgs, 0, &subheader))
		return Py_BuildException();
	char * title;
	if (!PyTuple_GetString(poArgs, 1, &title))
		return Py_BuildException();
	char * message;
	if (!PyTuple_GetString(poArgs, 2, &message))
		return Py_BuildException();
	char* to;
	if (!PyTuple_GetString(poArgs, 3, &to))
		return Py_BuildException();
	int itemid;
	if (!PyTuple_GetInteger(poArgs, 4, &itemid))
		return Py_BuildException();
	int gold;
	if (!PyTuple_GetInteger(poArgs, 5, &gold))
		return Py_BuildException();
	int won;
	if (!PyTuple_GetInteger(poArgs, 6, &won))
		return Py_BuildException();

	CPythonNetworkStream& asd = CPythonNetworkStream::Instance();
	asd.SendMailData(subheader, title, message, to, itemid, gold, won);
	return Py_BuildNone();
}

PyObject * GetItemMetinSocket(PyObject * poTarget, PyObject * poArgs)
{
	int pos;
	if (!PyTuple_GetInteger(poArgs, 0, &pos))
		return Py_BuildException();
	int iMetinSocketPos;
	if (!PyTuple_GetInteger(poArgs, 1, &iMetinSocketPos))
		return Py_BuildException();
	return Py_BuildValue("i", CMailBox::Instance().GetItemMetinSocket(pos, iMetinSocketPos));
}

PyObject * GetItemAttribute(PyObject * poTarget, PyObject * poArgs)
{
	int iIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iIndex))
		return Py_BuildException();
	int iAttrSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &iAttrSlotIndex))
		return Py_BuildException();

	if (iAttrSlotIndex >= 0 && iAttrSlotIndex < ITEM_ATTRIBUTE_SLOT_MAX_NUM)
	{
		BYTE byType;
		short sValue;
		CMailBox::Instance().GetItemAttribute(iIndex, iAttrSlotIndex, &byType, &sValue);
		return Py_BuildValue("ii", byType, sValue);
	}

	return Py_BuildValue("ii", 0, 0);
}

PyObject * MailCount(PyObject * poTarget, PyObject * poArgs)
{
	return Py_BuildValue("i", CMailBox::Instance().GetMailCount());
}
#ifdef ENABLE_CHANGE_LOOK_SYSTEM
PyObject * GetItemLook(PyObject * poSelf, PyObject * poArgs)
{
	int ipos;
	if (!PyTuple_GetInteger(poArgs, 0, &ipos))
		return Py_BadArgument();

	DWORD dwVnum = 0;
	CMailBox::Instance().GetItemLook(ipos, dwVnum);

	return Py_BuildValue("i", dwVnum);
}
#endif
PyObject * IsExistPage(PyObject * poTarget, PyObject * poArgs)
{
	return Py_BuildValue("i", CMailBox::Instance().IsExistPage());
}

PyObject * AcceptMailAll(PyObject * poSelf, PyObject * poArgs)
{
	CPythonNetworkStream::Instance().SendMailData(MAIL_SUBHEADER_ACCEPT_MAILS);
	return Py_BuildNone();
}

PyObject * RemoveMailAll(PyObject * poSelf, PyObject * poArgs)
{
	CPythonNetworkStream::Instance().SendMailData(MAIL_SUBHEADER_DELETE_MAILS);
	return Py_BuildNone();
}

void InitMailBox()
{
	static PyMethodDef bl_fnctns[] = {
		{ "GetRank", GetRank, METH_VARARGS },
		{ "SendMail", SendMail, METH_VARARGS },
		{ "AcceptMail", AcceptRank, METH_VARARGS },
		{ "RemoveMail", RemoveRank, METH_VARARGS },
		{ "AcceptMailAll", AcceptMailAll, METH_VARARGS },
		{ "RemoveMailAll", RemoveMailAll, METH_VARARGS },
		{ "GetItemAttribute", GetItemAttribute, METH_VARARGS },
		{ "GetItemMetinSocket", GetItemMetinSocket, METH_VARARGS },
		{ "SetRead", SetRead, METH_VARARGS },
		{ "RefreshMails", RefreshMails, METH_VARARGS },
		{ "MailCount", MailCount, METH_VARARGS },
		{ "IsExistPage", IsExistPage, METH_VARARGS },
		#ifdef ENABLE_CHANGE_LOOK_SYSTEM
		{ "GetItemLook", GetItemLook, METH_VARARGS },
		#endif
		{NULL, NULL, NULL},
	};
	
	PyObject* pModule = Py_InitModule("mailbox", bl_fnctns);
	PyModule_AddIntConstant(pModule, "LIMIT_RANGE", 1000);
	PyModule_AddIntConstant(pModule, "SHOW_COUNT", MAX_SLOT_RANK / 2);
	PyModule_AddIntConstant(pModule, "MAX_SLOT", MAX_SLOT_RANK);
}
#endif