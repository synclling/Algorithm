#pragma once

typedef int Object;

class Aggregate;

class Iterator
{
protected:
	Iterator();

public:
	virtual ~Iterator();

	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;

};

class ConcreteIterator : public Iterator
{
public:
	ConcreteIterator(Aggregate* pAggregate, int nIndex = 0);
	~ConcreteIterator();

	void First();
	void Next();
	bool IsDone();
	Object CurrentItem();

private:
	Aggregate*	m_pAggregate;
	int			m_nIndex;
};