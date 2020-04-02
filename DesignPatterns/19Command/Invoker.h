#pragma once

class Command;

class Invoker
{
public:
	Invoker(Command* pCommand);
	~Invoker();

	void Invoke();

private:
	Command* m_pCommand;
};
