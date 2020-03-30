#pragma once
#include "Component.h"
#include <vector>

class Composite : public Component
{
public:
	Composite();
	~Composite();

public:
	void Operation();
	void Add(Component* obj);
	void Remove(Component* obj);
	Component* GetChild(int index);

private:
	std::vector<Component*> m_vecComponent;
};