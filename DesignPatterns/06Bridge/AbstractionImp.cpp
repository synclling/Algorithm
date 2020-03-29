#include "pch.h"
#include "AbstractionImp.h"


AbstractionImp::AbstractionImp()
{
}


AbstractionImp::~AbstractionImp()
{
}


ConcreteAbstractionImpA::ConcreteAbstractionImpA()
{
}


ConcreteAbstractionImpA::~ConcreteAbstractionImpA()
{
}


void ConcreteAbstractionImpA::Operation()
{
	std::cout << "ConcreteAbstractionImpA..." << std::endl;
}


ConcreteAbstractionImpB::ConcreteAbstractionImpB()
{
}


ConcreteAbstractionImpB::~ConcreteAbstractionImpB()
{
}


void ConcreteAbstractionImpB::Operation()
{
	std::cout << "ConcreteAbstractionImpB..." << std::endl;
}