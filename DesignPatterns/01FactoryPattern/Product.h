#pragma once

class Product
{
protected:	// ÆÁ±Î¹¹Ôìº¯Êý
	Product();

public:
	virtual ~Product() = 0;
};


class ConcreteProduct : public Product
{
public:
	ConcreteProduct();
	~ConcreteProduct();
};