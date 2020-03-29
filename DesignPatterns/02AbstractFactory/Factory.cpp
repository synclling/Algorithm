#include "pch.h"
#include "Factory.h"
#include "ProductA.h"
#include "ProductB.h"


AbstractFactory::AbstractFactory()
{
}


AbstractFactory::~AbstractFactory()
{
}


ConcreteFactory1::ConcreteFactory1()
{
	std::cout << "ConcreteFactory1" << std::endl;
}


ConcreteFactory1::~ConcreteFactory1()
{
}


AbstractProductA *ConcreteFactory1::CreateProductA()
{
	return new ProductA1();
}


AbstractProductB *ConcreteFactory1::CreateProductB()
{
	return new ProductB1();
}


ConcreteFactory2::ConcreteFactory2()
{
	std::cout << "ConcreteFactory2" << std::endl;
}


ConcreteFactory2::~ConcreteFactory2()
{
}


AbstractProductA *ConcreteFactory2::CreateProductA()
{
	return new ProductA2();
}


AbstractProductB *ConcreteFactory2::CreateProductB()
{
	return new ProductB2();
}