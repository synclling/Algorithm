#pragma once

class Product
{
protected:	// ���ι��캯��
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