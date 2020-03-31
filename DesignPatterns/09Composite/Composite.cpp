#include "pch.h"
#include "Composite.h"

Composite::Composite()
{

}

Composite::~Composite()
{

}

void Composite::Operation()
{
	std::vector<Component*>::iterator it = m_vecComponent.begin();
	for (; it != m_vecComponent.end(); ++it)
	{
		(*it)->Operation();
	}
}

void Composite::Add(Component* obj)
{
	m_vecComponent.push_back(obj);
}

void Composite::Remove(Component* obj)
{
	std::vector<Component*>::iterator it = m_vecComponent.begin();
	for (; it != m_vecComponent.end(); ++it)
	{
		if ((*it) == obj)
		{
			m_vecComponent.erase(it);
		}
	}
}

Component* Composite::GetChild(int index)
{
	if (index < 0 || index > (int)m_vecComponent.size())
		return nullptr;

	return m_vecComponent[index];
}