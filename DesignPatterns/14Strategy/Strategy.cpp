#include "pch.h"
#include "Strategy.h"

Strategy::Strategy()
{

}

Strategy::~Strategy()
{

}


ConcreteStrategyA::ConcreteStrategyA()
{

}

ConcreteStrategyA::~ConcreteStrategyA()
{

}

void ConcreteStrategyA::AlgorithmInterface()
{
	std::cout << "ConcreteStrategyA Algorithm..." << std::endl;
}


ConcreteStrategyB::ConcreteStrategyB()
{

}

ConcreteStrategyB::~ConcreteStrategyB()
{

}

void ConcreteStrategyB::AlgorithmInterface()
{
	std::cout << "ConcreteStrategyB Algorithm..." << std::endl;
}