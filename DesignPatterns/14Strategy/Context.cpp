#include "pch.h"
#include "Context.h"
#include "Strategy.h"

Context::Context(Strategy* pStrategy) : m_pStrategy(pStrategy)
{

}

Context::~Context()
{
	SAFE_DELETE(m_pStrategy);
}

void Context::DoAction()
{
	m_pStrategy->AlgorithmInterface();
}