#pragma once

class Element;
class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
protected:
	Visitor();

public:
	virtual ~Visitor();

	virtual void VisitConcreteElementA(Element* pElement) = 0;
	virtual void VisitConcreteElementB(Element* pElement) = 0;
};

class ConcreteVisitorA : public Visitor
{
public:
	ConcreteVisitorA();
	~ConcreteVisitorA();

	virtual void VisitConcreteElementA(Element* pElement);
	virtual void VisitConcreteElementB(Element* pElement);
};

class ConcreteVisitorB : public Visitor
{
public:
	ConcreteVisitorB();
	~ConcreteVisitorB();

	virtual void VisitConcreteElementA(Element* pElement);
	virtual void VisitConcreteElementB(Element* pElement);
};