#pragma once

class Visitor;

class Element
{
protected:
	Element();

public:
	virtual ~Element();

	virtual void Accept(Visitor* pVisitor) = 0;
};

class ConcreteElementA : public Element
{
public:
	ConcreteElementA();
	~ConcreteElementA();

	void Accept(Visitor* pVisitor);
};

class ConcreteElementB : public Element
{
public:
	ConcreteElementB();
	~ConcreteElementB();

	void Accept(Visitor* pVisitor);
};