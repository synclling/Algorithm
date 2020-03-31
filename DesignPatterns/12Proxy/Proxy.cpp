#include "pch.h"
#include "Proxy.h"
#include "Subject.h"

Proxy::Proxy(Subject* pSubject)
{
	m_pSubject = pSubject;
}

Proxy::~Proxy()
{
	SAFE_DELETE(m_pSubject);
}

void Proxy::Request()
{
	std::cout << "Proxy Request..." << std::endl;
	m_pSubject->Request();
}