#include "pch.h"
#include "Handle.h"

Handle::Handle() : m_pSuccessor(nullptr)
{

}

Handle::Handle(Handle* pSuccessor) : m_pSuccessor(pSuccessor)
{

}

Handle::~Handle()
{
	SAFE_DELETE(m_pSuccessor);
}

Handle* Handle::GetSuccessor()
{
	return m_pSuccessor;
}

void Handle::SetSuccessor(Handle* pSuccessor)
{
	m_pSuccessor = pSuccessor;
}


ConcreteHandleA::ConcreteHandleA()
{

}

ConcreteHandleA::ConcreteHandleA(Handle* pSuccessor) : Handle(pSuccessor)
{

}

ConcreteHandleA::~ConcreteHandleA()
{

}

void ConcreteHandleA::HandleRequest()
{
	/* 此处应该是满足某个条件，将处理权交给特定的处理者 */
	if (GetSuccessor() != nullptr)
	{
		std::cout << "ConcreteHandleA: 我把处理权交给后继节点..." << std::endl;
		GetSuccessor()->HandleRequest();
	}
	else
	{
		std::cout << "ConcreteHandleA: 没有后继节点，我必须自己处理..." << std::endl;
	}
}


ConcreteHandleB::ConcreteHandleB()
{

}

ConcreteHandleB::ConcreteHandleB(Handle* pSuccessor) : Handle(pSuccessor)
{

}

ConcreteHandleB::~ConcreteHandleB()
{

}

void ConcreteHandleB::HandleRequest()
{
	/* 此处应该是满足某个条件，将处理权交给特定的处理者 */
	if (GetSuccessor() != nullptr)
	{
		std::cout << "ConcreteHandleB: 我把处理权交给后继节点..." << std::endl;
		GetSuccessor()->HandleRequest();
	}
	else
	{
		std::cout << "ConcreteHandleB: 没有后继节点，我必须自己处理..." << std::endl;
	}
}