#include "pch.h"
#include "Iterator.h"
#include "Aggregate.h"

Iterator::Iterator()
{

}

Iterator::~Iterator()
{

}


ConcreteIterator::ConcreteIterator(Aggregate* pAggregate, int nIndex)
{
	m_pAggregate = pAggregate;
	m_nIndex = nIndex;
}

ConcreteIterator::~ConcreteIterator()
{

}

void ConcreteIterator::First()
{
	m_nIndex = 0;
}

void ConcreteIterator::Next()
{
	if (m_nIndex < m_pAggregate->GetSize())
	{
		++m_nIndex;
	}
}

bool ConcreteIterator::IsDone()
{
	return (m_nIndex == m_pAggregate->GetSize());
}

Object ConcreteIterator::CurrentItem()
{
	return m_pAggregate->GetItem(m_nIndex);
}