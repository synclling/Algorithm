#pragma once

typedef int Object;

class Iterator;

class Aggregate
{
protected:
	Aggregate();

public:
	virtual ~Aggregate();

	virtual Iterator* CreateIterator() = 0;
	virtual Object GetItem(int index) = 0;
	virtual int	GetSize() = 0;
};

class ConcreteAggregate : public Aggregate
{
	enum { SIZE = 10 };

public:
	ConcreteAggregate();
	~ConcreteAggregate();

	Iterator* CreateIterator();
	Object GetItem(int index);
	int	GetSize();

private:
	Object m_Objects[SIZE];
};