#include "pch.h"
#include "Decorator.h"

Decorator::Decorator(Component* pComponent)
{
	m_pComponent = pComponent;
}

Decorator::~Decorator()
{
	SAFE_DELETE(m_pComponent)
}

void Decorator::Operation()
{

}


ConcreteDecorator::ConcreteDecorator(Component* pComponent) : Decorator(pComponent)
{

}

ConcreteDecorator::~ConcreteDecorator()
{

}

void ConcreteDecorator::Operation()
{
	m_pComponent->Operation();
	AddedBehavior();
}

void ConcreteDecorator::AddedBehavior()
{
	std::cout << "ConcreteDecorator::AddedBehavior..." << std::endl;
}