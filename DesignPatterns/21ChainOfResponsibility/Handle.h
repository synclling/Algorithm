#pragma once

class Handle
{
protected:
	Handle();
	Handle(Handle* pSuccessor);

public:
	virtual ~Handle();

	virtual void HandleRequest() = 0;

	Handle* GetSuccessor();
	void SetSuccessor(Handle* pSuccessor);

private:
	Handle* m_pSuccessor;
};

class ConcreteHandleA : public Handle
{
public:
	ConcreteHandleA();
	ConcreteHandleA(Handle* pSuccessor);
	~ConcreteHandleA();

	void HandleRequest();
};

class ConcreteHandleB : public Handle
{
public:
	ConcreteHandleB();
	ConcreteHandleB(Handle* pSuccessor);
	~ConcreteHandleB();

	void HandleRequest();
};