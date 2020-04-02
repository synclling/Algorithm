#include "pch.h"
#include "Subject.h"
#include "Observer.h"

Subject::Subject()
{

}

Subject::~Subject()
{

}

void Subject::Attach(Observer* pObserver)
{
	m_listObserver.push_front(pObserver);
}

void Subject::Detach(Observer* pObserver)
{
	if (pObserver != nullptr)
	{
		m_listObserver.remove(pObserver);
	}
}

void Subject::Notify()
{
	std::list<Observer*>::iterator it = m_listObserver.begin();
	for (; it != m_listObserver.end(); ++it)
	{
		(*it)->Update();
	}
}


ConcreteSubject::ConcreteSubject() : m_strState("")
{

}

ConcreteSubject::~ConcreteSubject()
{

}

std::string ConcreteSubject::GetState()
{
	return m_strState;
}

void ConcreteSubject::SetState(const std::string& strState)
{
	m_strState = strState;
}