#pragma once
#include "Component.h"

class Decorator : public Component
{
public:
	Decorator(Component* pComponent);
	~Decorator();

	void Operation();

protected:
	Component* m_pComponent;
};


class ConcreteDecorator : public Decorator
{
public:
	ConcreteDecorator(Component* pComponent);
	~ConcreteDecorator();

	void Operation();
	void AddedBehavior();
};