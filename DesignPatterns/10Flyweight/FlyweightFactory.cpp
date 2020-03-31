#include "pch.h"
#include "FlyweightFactory.h"
#include "Flyweight.h"

FlyweightFactory::FlyweightFactory()
{

}

FlyweightFactory::~FlyweightFactory()
{

}

Flyweight* FlyweightFactory::GetFlyweight(const std::string& key)
{
	std::vector<Flyweight*>::iterator it = m_vecFlyweight.begin();
	for (; it != m_vecFlyweight.end(); ++it)
	{
		if ((*it)->GetIntrinsicState() == key)
		{
			std::cout << "already create by users..." << std::endl;
			return (*it);
		}
	}

	Flyweight* pFlyweight = new ConcreteFlyweight(key);
	m_vecFlyweight.push_back(pFlyweight);

	return pFlyweight;
}