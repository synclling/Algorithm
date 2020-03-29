#include "pch.h"
#include "Builder.h"
#include "Product.h"


Builder::Builder()
{
}


Builder::~Builder()
{
}


ConcreteBuilder1::ConcreteBuilder1()
{
	m_pProduct = new Product();
}


ConcreteBuilder1::~ConcreteBuilder1()
{
	delete m_pProduct;
	m_pProduct = nullptr;
}


void ConcreteBuilder1::BuildPartA()
{
	std::cout << "Build partA of product...Set product's propertyA to X1" << std::endl;
}


void ConcreteBuilder1::BuildPartB()
{
	std::cout << "Build partB of product...Set product's propertyB to Y1" << std::endl;
}


void ConcreteBuilder1::BuildPartC()
{
	std::cout << "Build partC of product...Set product's propertyC to Z1" << std::endl;
}


Product* ConcreteBuilder1::GetProduct()
{
	return m_pProduct;
}



ConcreteBuilder2::ConcreteBuilder2()
{
	m_pProduct = new Product();
}


ConcreteBuilder2::~ConcreteBuilder2()
{
	delete m_pProduct;
	m_pProduct = nullptr;
}


void ConcreteBuilder2::BuildPartA()
{
	std::cout << "Build partA of product...Set product's propertyA to X2" << std::endl;
}


void ConcreteBuilder2::BuildPartB()
{
	std::cout << "Build partB of product...Set product's propertyB to Y2" << std::endl;
}


void ConcreteBuilder2::BuildPartC()
{
	std::cout << "Build partC of product...Set product's propertyC to Z2" << std::endl;
}


Product* ConcreteBuilder2::GetProduct()
{
	return m_pProduct;
}