#pragma once

class Component
{
protected:
	Component();

public:
	virtual ~Component();

	virtual void Operation();
};


class ConcreteComponent : public Component
{
public:
	ConcreteComponent();
	~ConcreteComponent();

	void Operation();
};