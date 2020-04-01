#pragma once

class Context;

// ³éÏó×´Ì¬Àà
class State
{
protected:
	State();

public:
	virtual ~State();

	virtual void OperationChangeState(Context* pContext) = 0;

protected:
	bool ChangeState(Context* pContext, State* pState);
};

class ConcreteStateA : public State
{
public:
	ConcreteStateA();
	~ConcreteStateA();

	void OperationChangeState(Context* pContext);
};

class ConcreteStateB : public State
{
public:
	ConcreteStateB();
	~ConcreteStateB();

	void OperationChangeState(Context* pContext);
};