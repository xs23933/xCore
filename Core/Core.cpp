// Core.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Core.h"

// 入口
// +---------------------------------------------------------------+
// + 后面写成windows程序使用的。 备用
// +---------------------------------------------------------------+

//int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
//                     _In_opt_ HINSTANCE hPrevInstance,
//                     _In_ LPTSTR    lpCmdLine,
//                     _In_ int       nCmdShow){
//	UNREFERENCED_PARAMETER(hPrevInstance);
//	UNREFERENCED_PARAMETER(lpCmdLine);
//	MSG msg;
//	HACCEL hAccelTable;
//
//	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CORE));
//
//	// 主消息循环:
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//
//	return (int) msg.wParam;
//}

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
