#include "pch.h"
#include "Visitor.h"
#include "Element.h"

Visitor::Visitor()
{

}

Visitor::~Visitor()
{

}

ConcreteVisitorA::ConcreteVisitorA()
{

}

ConcreteVisitorA::~ConcreteVisitorA()
{

}

void ConcreteVisitorA::VisitConcreteElementA(Element* pElement)
{
	std::cout << "ConcreteVisitorA: I will visit ConcreteElementA..." << std::endl;
}

void ConcreteVisitorA::VisitConcreteElementB(Element* pElement)
{
	std::cout << "ConcreteVisitorA: I will visit ConcreteElementB..." << std::endl;
}

ConcreteVisitorB::ConcreteVisitorB()
{

}

ConcreteVisitorB::~ConcreteVisitorB()
{

}

void ConcreteVisitorB::VisitConcreteElementA(Element* pElement)
{
	std::cout << "ConcreteVisitorB: I will visit ConcreteElementA..." << std::endl;
}

void ConcreteVisitorB::VisitConcreteElementB(Element* pElement)
{
	std::cout << "ConcreteVisitorB: I will visit ConcreteElementB..." << std::endl;
}