#pragma once
#include <string>

class Flyweight
{
protected:
	Flyweight(std::string strIntrinsicState);

public:
	virtual ~Flyweight();

	virtual void Operation(const std::string& strExtrinsicState);
	std::string GetIntrinsicState();

private:
	std::string m_strIntrinsicState;
};

class ConcreteFlyweight : public Flyweight
{
public:
	ConcreteFlyweight(std::string strIntrinsicState);
	~ConcreteFlyweight();

	void Operation(const std::string& strExtrinsicState);
};