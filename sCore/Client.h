#pragma once
#include "thread.h"
class CClient :
	public Thread
{
public:
	CClient(void);
	virtual ~CClient(void);
	int Run();
private:
	SOCKET m_sock;
	sockaddr_in m_saddr;
};

