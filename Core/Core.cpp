// Core.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Core.h"

// ���
int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA data;
	WSAStartup(MAKEWORD(2,2), &data);
	CCore core;
	core.run();
	WSACleanup();
	return 0;
}
// �ۺ���� ���򹫹��๹��
CCore::CCore(void){
	m_run = true;
	m_server =  new CServer();
}


CCore::~CCore(void){
}


void CCore::run(void)
{
	// ���д��������
	m_server->run();
}
