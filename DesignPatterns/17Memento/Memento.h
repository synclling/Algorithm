#pragma once
#include <string>

class Originator;

class Memento
{
	friend class Originator;

private:
	Memento(const std::string& strState);
	~Memento();

	std::string GetState();
	void Set(const std::string& strState);

private:
	std::string m_strState;
};
