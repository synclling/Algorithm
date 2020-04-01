#include "pch.h"
#include "State.h"
#include "Context.h"

State::State()
{

}

State::~State()
{

}

bool State::ChangeState(Context* pContext, State* pState)
{
	pContext->ChangeState(pState);
	return true;
}


ConcreteStateA::ConcreteStateA()
{

}

ConcreteStateA::~ConcreteStateA()
{

}

void ConcreteStateA::OperationChangeState(Context* pContext)
{
	std::cout << "ConcreteStateA" << std::endl;
	ChangeState(pContext, new ConcreteStateB());
}


ConcreteStateB::ConcreteStateB()
{

}

ConcreteStateB::~ConcreteStateB()
{

}

void ConcreteStateB::OperationChangeState(Context* pContext)
{
	std::cout << "ConcreteStateB" << std::endl;
	ChangeState(pContext, new ConcreteStateA());
}