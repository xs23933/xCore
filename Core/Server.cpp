#include "stdafx.h"
#include "Server.h"

// 监听代理端口
// 监听成功后通知服务器上线

CServer::CServer(void)
{
	m_port = 6000;
	// 设置代理服务器sockaddr
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
	// 创建代理服务线程并启动端口监听
	m_threadid = _beginthread(&CServer::threadMethod, 0, this);
	while(true){Sleep(1);}
}

void CServer::threadMethod(void * arg)
{
	// 线程代理函数
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
	// 设置端口重用
	setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&flag, sizeof(int));

	if(SOCKET_ERROR == ::bind(m_sock, (SOCKADDR *)&m_sockaddr, sizeof(m_sockaddr))){
		// 绑定端口失败, ----需要完善另外选择端口
		Close();
		return false;
	}
	if(SOCKET_ERROR == ::listen(m_sock, SOMAXCONN)){
		// 监听端口失败, ----需完善另外选择或异常处理工作
		Close();
		return false;
	}
	// 接收数据并创建新线程处理请求
	while(1){

		std::cout<<"test"<<std::endl;
		Sleep(1000);
	}
	return true;
}
