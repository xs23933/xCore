#include "Client.h"
// ���ڷ�����ͨ����

#define PORT 23932

CClient::CClient(void)
{
	// �������˿�ip���� ��{ע��}�������ó����� ������
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
// ��������д��������������֣� �����߷�����������proxy�˿�
int CClient::Run(){
	return 0;
}