#include "pch.h"
#include "Memento.h"

Memento::Memento(const std::string& strState) : m_strState(strState)
{

}

Memento::~Memento()
{

}

std::string Memento::GetState()
{
	return m_strState;
}

void Memento::Set(const std::string& strState)
{
	m_strState = strState;
}