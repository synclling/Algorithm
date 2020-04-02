#include "pch.h"
#include "Mediator.h"
#include "Colleague.h"

Mediator::Mediator()
{

}

Mediator::~Mediator()
{

}

ConcreteMediator::ConcreteMediator()
{

}

ConcreteMediator::ConcreteMediator(Colleague* pColleagueA, Colleague* pColleagueB)
{
	m_pColleagueA = pColleagueA;
	m_pColleagueB = pColleagueB;
}

ConcreteMediator::~ConcreteMediator()
{

}

void ConcreteMediator::DoActionFromAToB()
{
	m_pColleagueB->SetState(m_pColleagueA->GetState());
}

void ConcreteMediator::DoActionFromBToA()
{
	m_pColleagueA->SetState(m_pColleagueB->GetState());
}

void ConcreteMediator::IntroColleague(Colleague* pColleagueA, Colleague* pColleagueB)
{
	m_pColleagueA = pColleagueA;
	m_pColleagueB = pColleagueB;
}

void ConcreteMediator::PrintInfo()
{
	std::cout << "State of ConcreteColleagueA: " << m_pColleagueA->GetState() << std::endl;
	std::cout << "State of ConcreteColleagueB: " << m_pColleagueB->GetState() << std::endl;
}

Colleague* ConcreteMediator::GetConcreteColleagueA()
{
	return m_pColleagueA;
}

Colleague* ConcreteMediator::GetConcreteColleagueB()
{
	return m_pColleagueB;
}

void ConcreteMediator::SetConcreteColleagueA(Colleague* pColleagueA)
{
	m_pColleagueA = pColleagueA;
}

void ConcreteMediator::SetConcreteColleagueB(Colleague* pColleagueB)
{
	m_pColleagueB = pColleagueB;
}