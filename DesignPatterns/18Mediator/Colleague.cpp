#include "pch.h"
#include "Colleague.h"
#include "Mediator.h"

Colleague::Colleague()
{

}

Colleague::Colleague(Mediator* pMediator) : m_pMediator(pMediator)
{

}

Colleague::~Colleague()
{

}


ConcreteColleagueA::ConcreteColleagueA()
{

}

ConcreteColleagueA::ConcreteColleagueA(Mediator* pMediator) : Colleague(pMediator)
{

}

ConcreteColleagueA::~ConcreteColleagueA()
{

}

void ConcreteColleagueA::Action()
{
	m_pMediator->DoActionFromAToB();
	//std::cout << "State of ConcreteColleagueA: " << GetState() << std::endl;
}

std::string ConcreteColleagueA::GetState()
{
	return m_strState;
}

void ConcreteColleagueA::SetState(const std::string& strState)
{
	m_strState = strState;
}


ConcreteColleagueB::ConcreteColleagueB()
{

}

ConcreteColleagueB::ConcreteColleagueB(Mediator* pMediator) : Colleague(pMediator)
{

}

ConcreteColleagueB::~ConcreteColleagueB()
{

}

void ConcreteColleagueB::Action()
{
	m_pMediator->DoActionFromBToA();
	//std::cout << "State of ConcreteColleagueB: " << GetState() << std::endl;
}

std::string ConcreteColleagueB::GetState()
{
	return m_strState;
}

void ConcreteColleagueB::SetState(const std::string& strState)
{
	m_strState = strState;
}