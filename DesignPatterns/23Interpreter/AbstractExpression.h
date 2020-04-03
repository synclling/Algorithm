#pragma once
#include <string>

class Context;

class AbstractExpression
{
protected:
	AbstractExpression();

public:
	virtual ~AbstractExpression();

	virtual void Interpret(const Context& context) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
	TerminalExpression(const std::string& strStatement);
	~TerminalExpression();

	void Interpret(const Context& context);

private:
	std::string m_strStatement;
};

class NonterminalExpression : public AbstractExpression
{
public:
	NonterminalExpression(AbstractExpression* pExpression, int nTimes);
	~NonterminalExpression();

	void Interpret(const Context& context);

private:
	AbstractExpression* m_pExpression;
	int m_nTimes;
};