#pragma once
// tcp��͸������

class CTraversal
{
public:
	CTraversal(void);
	virtual ~CTraversal(void);
	void run(void);
	unsigned m_threadid;
	static void threadMethod(void * arg);
	bool work(void);

};

