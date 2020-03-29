#pragma once

class AbstractProductB
{
protected:
	AbstractProductB();

public:
	virtual ~AbstractProductB() = 0;
};


class ProductB1 : public AbstractProductB
{
public:
	ProductB1();
	~ProductB1();
};


class ProductB2 : public AbstractProductB
{
public:
	ProductB2();
	~ProductB2();
};