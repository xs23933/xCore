#include "stdafx.h"
#include "Server.h"

// ��������˿�
// �����ɹ���֪ͨ����������

CServer::CServer(void)
{
	m_port = 6000;
	// ���ô��������sockaddr
	m_sockaddr.sin_family = AF_INET;
	m_sockaddr.sin_addr.S_un.S_addr = ::htonl(INADDR_ANY);
	m_sockaddr.sin_port = ::htons(m_port);
}

CServer::~CServer(void)
{
}

void CServer::Close(void){
	::closesocket(m_sock);
}
bool CServer::proxy(void){
	listen();
}

void CServer::run(void)
{
	// ������������̲߳������˿ڼ���
	m_threadid = _beginthread(&CServer::threadMethod, 0, this);
	while(true){Sleep(1);}
}

void CServer::threadMethod(void * arg)
{
	// �̴߳�����
	CServer * svr = reinterpret_cast<CServer *>(arg);
	if (NULL != svr){
		svr->proxy();
		_endthreadex(svr->m_threadid);
	}
}

bool CServer::listen(void)
{
	int flag = 1, intlen = sizeof(int);
	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// ���ö˿�����
	setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&flag, sizeof(int));

	if(SOCKET_ERROR == ::bind(m_sock, (SOCKADDR *)&m_sockaddr, sizeof(m_sockaddr))){
		// �󶨶˿�ʧ��, ----��Ҫ��������ѡ��˿�
		Close();
		return false;
	}
	if(SOCKET_ERROR == ::listen(m_sock, SOMAXCONN)){
		// �����˿�ʧ��, ----����������ѡ����쳣������
		Close();
		return false;
	}
	// �������ݲ��������̴߳�������
	while(1){

		std::cout<<"test"<<std::endl;
		Sleep(1000);
	}
	return true;
}
