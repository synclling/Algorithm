#pragma once

class Strategy
{
protected:
	Strategy();

public:
	virtual ~Strategy();

	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
	ConcreteStrategyA();
	~ConcreteStrategyA();

	void AlgorithmInterface();
};

class ConcreteStrategyB : public Strategy
{
public:
	ConcreteStrategyB();
	~ConcreteStrategyB();

	void AlgorithmInterface();
};