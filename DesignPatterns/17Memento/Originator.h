#pragma once
#include <string>

class Memento;

class Originator
{
public:
	Originator();
	Originator(const std::string& strState);
	~Originator();

	Memento* CreateMemento();
	void RestoreToMemento(Memento* pMemento);

	std::string GetState();
	void SetState(const std::string& strState);
	void PrintState();

private:
	std::string m_strState;
	Memento*	m_pMemento;
};