#include "stdafx.h"
#include "Traversal.h"
// tcp��͸������

CTraversal::CTraversal(void)
{
}

CTraversal::~CTraversal(void)
{
}




void CTraversal::run(void)
{
	// ������͸�����̲߳������˿ڼ���
	m_threadid = _beginthread(&CTraversal::threadMethod, 0, this);
	while(true){Sleep(1);}
}


void CTraversal::threadMethod(void * arg)
{
	// �̴߳�����
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
