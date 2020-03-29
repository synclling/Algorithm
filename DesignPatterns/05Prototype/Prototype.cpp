#include "pch.h"
#include "Prototype.h"


Prototype::Prototype()
{
}


Prototype::~Prototype()
{
}



ConcretePrototype::ConcretePrototype()
{
}


ConcretePrototype::ConcretePrototype(const ConcretePrototype& obj)
{
}


ConcretePrototype::~ConcretePrototype()
{
}


Prototype* ConcretePrototype::Clone() const
{
	return new ConcretePrototype(*this);
}