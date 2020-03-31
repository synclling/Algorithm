#include "pch.h"
#include "Flyweight.h"

Flyweight::Flyweight(std::string strIntrinsicState)
{
	m_strIntrinsicState = strIntrinsicState;
}

Flyweight::~Flyweight()
{

}

void Flyweight::Operation(const std::string& strExtrinsicState)
{

}

std::string Flyweight::GetIntrinsicState()
{
	return m_strIntrinsicState;
}


ConcreteFlyweight::ConcreteFlyweight(std::string strIntrinsicState) : Flyweight(strIntrinsicState)
{
	std::cout << "ConcreteFlyweight Build..." << strIntrinsicState << std::endl;
}

ConcreteFlyweight::~ConcreteFlyweight()
{

}

void ConcreteFlyweight::Operation(const std::string& strExtrinsicState)
{
	std::cout << "ConcreteFlyweight: Intrinsic[" << GetIntrinsicState()
		<< "] ExtrinsicState[" << strExtrinsicState << "]" << std::endl;
}