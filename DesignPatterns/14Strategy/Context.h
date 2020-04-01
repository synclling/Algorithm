#pragma once

class Strategy;

class Context
{
public:
	Context(Strategy* pStrategy);
	~Context();

	void DoAction();

private:
	Strategy* m_pStrategy;
};
