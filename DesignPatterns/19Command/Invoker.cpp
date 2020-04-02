#include "pch.h"
#include "Invoker.h"
#include "Command.h"


Invoker::Invoker(Command* pCommand) : m_pCommand(pCommand)
{

}

Invoker::~Invoker()
{
	SAFE_DELETE(m_pCommand);
}

void Invoker::Invoke()
{
	m_pCommand->Excute();
}