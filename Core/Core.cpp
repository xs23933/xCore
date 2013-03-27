// Core.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Core.h"

// 入口
int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA data;
	WSAStartup(MAKEWORD(2,2), &data);
	CCore core;
	core.run();
	WSACleanup();
	return 0;
}
// 综合入口 程序公共类构造
CCore::CCore(void){
	m_run = true;
	m_server =  new CServer();
}


CCore::~CCore(void){
}


void CCore::run(void)
{
	// 运行代理服务器
	m_server->run();
}
