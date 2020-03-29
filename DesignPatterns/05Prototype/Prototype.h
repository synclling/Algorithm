#pragma once
class Prototype
{
protected:
	Prototype();

public:
	virtual ~Prototype();

	virtual Prototype* Clone() const = 0;
};


class ConcretePrototype : public Prototype
{
public:
	ConcretePrototype();
	ConcretePrototype(const ConcretePrototype& obj);
	~ConcretePrototype();

	Prototype* Clone() const;
};