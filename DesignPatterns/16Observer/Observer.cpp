#include "pch.h"
#include "Observer.h"
#include "Subject.h"

Observer::Observer() : m_strState("")
{

}

Observer::~Observer()
{

}

ConcreteObserverA::ConcreteObserverA(Subject* pSubject) : m_pSubject(pSubject)
{
	m_pSubject->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA()
{
	m_pSubject->Detach(this);
}

void ConcreteObserverA::Update()
{
	m_strState = m_pSubject->GetState();
	PrintInfo();
}

void ConcreteObserverA::PrintInfo()
{
	std::cout << "ConcreteObserverA observer..." << m_strState << std::endl;
}


ConcreteObserverB::ConcreteObserverB(Subject* pSubject) : m_pSubject(pSubject)
{
	m_pSubject->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB()
{
	m_pSubject->Detach(this);
}

void ConcreteObserverB::Update()
{
	m_strState = m_pSubject->GetState();
	PrintInfo();
}

void ConcreteObserverB::PrintInfo()
{
	std::cout << "ConcreteObserverB observer..." << m_strState << std::endl;
}