#include "pch.h"
#include "Aggregate.h"
#include "Iterator.h"


Aggregate::Aggregate()
{

}

Aggregate::~Aggregate()
{

}

ConcreteAggregate::ConcreteAggregate()
{
	for (int i = 0; i < SIZE; ++i)
	{
		m_Objects[i] = i;
	}
}

ConcreteAggregate::~ConcreteAggregate()
{

}

Iterator* ConcreteAggregate::CreateIterator()
{
	return new ConcreteIterator(this);
}

Object ConcreteAggregate::GetItem(int index)
{
	if (index < 0 || index > GetSize())
		return -200;

	return m_Objects[index];
}

int	ConcreteAggregate::GetSize()
{
	return SIZE;
}