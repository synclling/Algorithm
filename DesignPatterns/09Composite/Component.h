#pragma once

class Component
{
public:
	Component();
	virtual ~Component();

public:
	virtual void Operation() = 0;
	virtual void Add(Component* obj);
	virtual void Remove(Component* obj);
	virtual Component* GetChild(int index);
};
