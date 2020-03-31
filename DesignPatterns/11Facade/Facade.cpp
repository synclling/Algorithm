#include "pch.h"
#include "Facade.h"
#include "Subsystem1.h"
#include "Subsystem2.h"

Facade::Facade()
{
	m_pSubsystem1 = new Subsystem1();
	m_pSubsystem2 = new Subsystem2();
}

Facade::~Facade()
{
	SAFE_DELETE(m_pSubsystem1);
	SAFE_DELETE(m_pSubsystem2);
}

void Facade::OperationWrapper()
{
	m_pSubsystem1->Operation();
	m_pSubsystem2->Operation();
}