#pragma once
#include <string>

//class Context;
//
//// 抽象表达式
//class AbstractExpression
//{
//protected:
//	AbstractExpression();
//
//public:
//	virtual ~AbstractExpression();
//
//	// 解释器接口
//	virtual void Interpret(const Context& context) = 0;
//};
//
///*
// *	终结符表达式，实现与文法中的终结符相关联的解释操作
// *	通常一个解释器模式中只能有一个终结符表达式，但有多个实例，对应不同的终结符
// */
//class TerminalExpression : public AbstractExpression
//{
//public:
//	TerminalExpression(const std::string& strStatement);
//	~TerminalExpression();
//
//	void Interpret(const Context& context);
//
//private:
//	std::string m_strStatement;
//};
//
///*
// *	非终结符表达式，为文法中的非终结符实现解释操作
// *	文法中的每条规则对应一个非终结符表达式
// */
//class NonterminalExpression : public AbstractExpression
//{
//public:
//	NonterminalExpression(AbstractExpression* pExpression, int nTimes);
//	~NonterminalExpression();
//
//	void Interpret(const Context& context);
//
//private:
//	AbstractExpression* m_pExpression;
//	int m_nTimes;
//};