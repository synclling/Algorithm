#include "pch.h"
#include "Component.h"

Component::Component()
{

}

Component::~Component()
{

}

void Component::Operation()
{

}


ConcreteComponent::ConcreteComponent()
{

}

ConcreteComponent::~ConcreteComponent()
{

}

void ConcreteComponent::Operation()
{
	std::cout << "ConcreteComponent::Operation..." << std::endl;
}