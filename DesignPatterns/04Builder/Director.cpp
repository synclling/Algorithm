#include "pch.h"
#include "Director.h"
#include "Builder.h"


Director::Director(Builder* pBuilder)
{
	m_pBuilder = pBuilder;
}


Director::~Director()
{
	delete m_pBuilder;
	m_pBuilder = nullptr;
}


void Director::Construct()
{
	m_pBuilder->BuildPartA();
	m_pBuilder->BuildPartB();
	m_pBuilder->BuildPartC();
}