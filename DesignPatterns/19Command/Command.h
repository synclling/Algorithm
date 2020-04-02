#pragma once

class Receiver;

class Command
{
public:
	virtual ~Command();

	virtual void Excute() = 0;

protected:
	Command();
};

class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver* pReceiver);
	~ConcreteCommand();

	void Excute();

private:
	Receiver* m_pReceiver;
};