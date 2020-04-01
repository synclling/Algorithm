#include "pch.h"
#include "Context.h"
#include "State.h"

Context::Context(State* pState) : m_pState(pState)
{

}

Context::~Context()
{
	//SAFE_DELETE(m_pState);
}

void Context::OperationChangeState()
{
	m_pState->OperationChangeState(this);
}

bool Context::ChangeState(State* pState)
{
	m_pState = pState;
	return true;
}