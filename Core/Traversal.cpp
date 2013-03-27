#include "stdafx.h"
#include "Traversal.h"
// tcp穿透功能类

CTraversal::CTraversal(void)
{
}

CTraversal::~CTraversal(void)
{
}




void CTraversal::run(void)
{
	// 创建穿透工作线程并启动端口监听
	m_threadid = _beginthread(&CTraversal::threadMethod, 0, this);
	while(true){Sleep(1);}
}


void CTraversal::threadMethod(void * arg)
{
	// 线程代理函数
	CTraversal * traver = reinterpret_cast<CTraversal *>(arg);
	if (NULL != traver){
		traver->work();
		_endthreadex(traver->m_threadid);
	}
}


bool CTraversal::work(void)
{
	return false;
}
