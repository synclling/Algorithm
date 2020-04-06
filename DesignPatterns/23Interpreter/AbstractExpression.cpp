#include "pch.h"
#include "AbstractExpression.h"
#include "Context.h"

//AbstractExpression::AbstractExpression()
//{
//
//}
//
//AbstractExpression::~AbstractExpression()
//{
//
//}
//
//
//TerminalExpression::TerminalExpression(const std::string& strStatement)
//{
//	m_strStatement = strStatement;
//}
//
//TerminalExpression::~TerminalExpression()
//{
//
//}
//
//void TerminalExpression::Interpret(const Context& context)
//{
//	std::cout << m_strStatement << " TerminalExpression" << std::endl;
//}
//
//
//NonterminalExpression::NonterminalExpression(AbstractExpression* pExpression, int nTimes)
//{
//	m_pExpression = pExpression;
//	m_nTimes = nTimes;
//}
//
//NonterminalExpression::~NonterminalExpression()
//{
//
//}
//
//void NonterminalExpression::Interpret(const Context& context)
//{
//	for (int i = 0; i < m_nTimes; ++i)
//	{
//		m_pExpression->Interpret(context);
//	}
//}