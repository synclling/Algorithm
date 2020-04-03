#include "pch.h"
#include "Element.h"
#include "Visitor.h"

Element::Element()
{

}

Element::~Element()
{

}

ConcreteElementA::ConcreteElementA()
{

}

ConcreteElementA::~ConcreteElementA()
{

}

void ConcreteElementA::Accept(Visitor* pVisitor)
{
	std::cout << "visiting ConcreteElementA..." << std::endl;
	pVisitor->VisitConcreteElementA(this);
}

ConcreteElementB::ConcreteElementB()
{

}

ConcreteElementB::~ConcreteElementB()
{

}

void ConcreteElementB::Accept(Visitor* pVisitor)
{
	std::cout << "visiting ConcreteElementB..." << std::endl;
	pVisitor->VisitConcreteElementB(this);
}