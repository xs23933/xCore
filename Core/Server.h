#pragma once
class CServer
{
public:
	CServer(void);
	~CServer(void);
	void run(void);
	static void threadMethod(void * arg);
	bool proxy(void);
	SOCKET m_sock;
	sockaddr_in m_sockaddr;
	int m_port;
protected:
	unsigned m_threadid;
	void Close(void);
	bool listen(void);
};

