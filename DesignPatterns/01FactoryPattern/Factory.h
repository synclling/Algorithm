#pragma once

class Product;

class Factory
{
protected:
	Factory();

public:
	virtual ~Factory();

	virtual Product *CreateProduct() = 0;
};


class ConcreteFactory : public Factory
{
public:
	ConcreteFactory();
	~ConcreteFactory();

	Product *CreateProduct();
};