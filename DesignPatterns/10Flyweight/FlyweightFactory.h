#pragma once
#include <string>
#include <vector>

class Flyweight;

class FlyweightFactory
{
public:
	FlyweightFactory();
	~FlyweightFactory();

	Flyweight* GetFlyweight(const std::string& key);

private:
	std::vector<Flyweight*> m_vecFlyweight;
};
