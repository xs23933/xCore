// Core.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Core.h"

// ���
// +---------------------------------------------------------------+
// + ����д��windows����ʹ�õġ� ����
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
//	// ����Ϣѭ��:
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
