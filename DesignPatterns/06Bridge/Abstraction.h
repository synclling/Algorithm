#pragma once

class AbstractionImp;

class Abstraction
{
protected:
	Abstraction();

public:
	virtual ~Abstraction();

	virtual void Operation() = 0;
};


class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(AbstractionImp* pAbstractionImp);
	~RefinedAbstraction();

	void Operation();

private:
	AbstractionImp* m_pAbstractionImp;
};