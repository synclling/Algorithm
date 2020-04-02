#include "pch.h"
#include "Command.h"
#include "Receiver.h"

Command::Command()
{

}

Command::~Command()
{

}

ConcreteCommand::ConcreteCommand(Receiver* pReceiver) : m_pReceiver(pReceiver)
{

}

ConcreteCommand::~ConcreteCommand()
{
	SAFE_DELETE(m_pReceiver);
}

void ConcreteCommand::Excute()
{
	m_pReceiver->Action();
}