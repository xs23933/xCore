#pragma once
#include "Server.h"
#include "resource.h"
// �ۺ����
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

