#pragma once
class AbstractionImp
{
protected:
	AbstractionImp();

public:
	virtual ~AbstractionImp();

	virtual void Operation() = 0;
};


class ConcreteAbstractionImpA : public AbstractionImp
{
public:
	ConcreteAbstractionImpA();
	~ConcreteAbstractionImpA();

	void Operation();
};


class ConcreteAbstractionImpB : public AbstractionImp
{
public:
	ConcreteAbstractionImpB();
	~ConcreteAbstractionImpB();

	void Operation();
};