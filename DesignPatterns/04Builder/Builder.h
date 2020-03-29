#pragma once
#include <string>

class Product;

class Builder
{
protected:
	Builder();

public:
	virtual ~Builder();

	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual void BuildPartC() = 0;
	virtual Product* GetProduct() = 0;
};


class ConcreteBuilder1 : public Builder
{
public:
	ConcreteBuilder1();
	~ConcreteBuilder1();

	void BuildPartA();
	void BuildPartB();
	void BuildPartC();
	Product* GetProduct();

private:
	Product* m_pProduct;
};


class ConcreteBuilder2 : public Builder
{
public:
	ConcreteBuilder2();
	~ConcreteBuilder2();

	void BuildPartA();
	void BuildPartB();
	void BuildPartC();
	Product* GetProduct();

private:
	Product* m_pProduct;
};