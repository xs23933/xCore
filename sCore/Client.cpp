#include "Client.h"
// 关于服务器通信类

#define PORT 23932

CClient::CClient(void)
{
	// 服务器端口ip设置 （{注意}必须设置成域名 发布后）
	m_sock = INVALID_SOCKET;
	memset(&m_saddr,0,sizeof(sockaddr_in));
	m_saddr.sin_family = AF_INET;
	m_saddr.sin_addr.s_addr = inet_addr("192.168.1.88");
	m_saddr.sin_port = htons(PORT);
}

CClient::~CClient(void)
{
	if(INVALID_SOCKET != m_sock){
		closesocket(m_sock);
		m_sock = INVALID_SOCKET;
	}
}
// 请在这里写初次与服务器握手， 并告诉服务器监听的proxy端口
int CClient::Run(){
	return 0;
}