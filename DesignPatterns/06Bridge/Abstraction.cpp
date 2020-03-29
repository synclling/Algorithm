#include "pch.h"
#include "Abstraction.h"
#include "AbstractionImp.h"


Abstraction::Abstraction()
{
}


Abstraction::~Abstraction()
{
}


RefinedAbstraction::RefinedAbstraction(AbstractionImp* pAbstractionImp)
{
	m_pAbstractionImp = pAbstractionImp;
}


RefinedAbstraction::~RefinedAbstraction()
{
}


void RefinedAbstraction::Operation()
{
	m_pAbstractionImp->Operation();
}