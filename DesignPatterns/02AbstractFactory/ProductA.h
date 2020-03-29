#pragma once

class AbstractProductA
{
protected:
	AbstractProductA();

public:
	virtual ~AbstractProductA() = 0;
};

class ProductA1 : public AbstractProductA
{
public:
	ProductA1();
	~ProductA1();
};

class ProductA2 : public AbstractProductA
{
public:
	ProductA2();
	~ProductA2();
};