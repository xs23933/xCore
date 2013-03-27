#pragma once
#include "Server.h"
// вш╨охК©з
class CCore
{
public:
	CCore(void);
	~CCore(void);
	void run(void);
protected:
	bool  m_run;
	CServer * m_server;
};

