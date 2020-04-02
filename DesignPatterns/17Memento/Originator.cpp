#include "pch.h"
#include "Originator.h"
#include "Memento.h"

Originator::Originator() : m_strState(""), m_pMemento(nullptr)
{

}

Originator::Originator(const std::string& strState)
{
	m_strState = strState;
	m_pMemento = nullptr;
}

Originator::~Originator()
{
	SAFE_DELETE(m_pMemento);
}

Memento* Originator::CreateMemento()
{
	SAFE_DELETE(m_pMemento);

	m_pMemento = new Memento(m_strState);
	return m_pMemento;
}

void Originator::RestoreToMemento(Memento* pMemento)
{
	m_strState = pMemento->GetState();
}

std::string Originator::GetState()
{
	return m_strState;
}

void Originator::SetState(const std::string& strState)
{
	m_strState = strState;
}

void Originator::PrintState()
{
	std::cout << "Originator State..." << m_strState << std::endl;
}