// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include "pch.h"
//#include "Context.h"
//#include "AbstractExpression.h"
//
//int main()
//{
//    std::cout << "Hello World!\n"; 
//
//	Context* pConext = new Context();
//
//	AbstractExpression* pTE = new TerminalExpression("hello");
//	AbstractExpression* pNTE = new NonterminalExpression(pTE, 2);
//
//	pNTE->Interpret(*pConext);
//
//	SAFE_DELETE(pNTE);
//	SAFE_DELETE(pTE);
//	SAFE_DELETE(pConext);
//
//	return 0;
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


/* 
 *   解释器模式--使用示例
 *   解释表达式'LOOP 2 PRINT 杨过 SPACE SPACE PRINT 小龙女 BREAK END PRINT 郭靖 SPACE SPACE PRINT 黄蓉'
 *   输出：
 *       杨过  小龙女
 *       杨过  小龙女
 *       郭靖  黄蓉
 *
 */

#include "pch.h"
#include <string>
#include <list>

// 上下文类，提供了处理指令的方法
class Context
{
public:
	Context(const std::string& strText);
	~Context();

	std::string GetCurrentCommand() const;
	void NextCommand();
	int GetLoopNumber();

protected:
	void SplitString(const std::string& strText);	// 默认以空格为分割符

private:
	std::list<std::string> m_listCommandSet;	// 经过处理后的指令集合
	std::string m_strCurrentCommand;			// 记录当前的单个指令
};

// 抽象表达式
class Expression
{
protected:
	Expression();

public:
	virtual ~Expression();

	virtual void interpret(Context* context) = 0;
	virtual void execute() = 0;
};

// 指令集合(非终结符表达式)，解释Context生成各个指令
class CommandSet : public Expression
{
public:
	CommandSet();
	~CommandSet();

	void interpret(Context* context);
	void execute();

private:
	std::list<Expression*> m_listCommands;
};

// 单条指令(非终结符表达式)，包括LoopCommand和PrimitiveCommand
class Command : public Expression
{
public:
	Command();
	~Command();

	void interpret(Context* context);
	void execute();

private:
	Expression* m_pCommand;
};


// 循环指令(非终结符表达式)，解释执行循环命令
class LoopCommand : public Expression
{
public:
	LoopCommand();
	~LoopCommand();

	void interpret(Context* context);
	void execute();

private:
	Expression* m_pExpression;
	int m_nNumber;	// 循环次数
};

// 元指令(终结符表达式)，解释执行基本指令
class PrimitiveCommand : public Expression
{
public:
	PrimitiveCommand();
	~PrimitiveCommand();

	void interpret(Context* context);
	void execute();

private:
	std::string m_strCommand;
	std::string m_strText;
};


// --------------------------------------------------

Context::Context(const std::string& strText)
{
	SplitString(strText);
	NextCommand();	// 指向第一条指令
}

Context::~Context()
{

}

std::string Context::GetCurrentCommand() const
{
	return m_strCurrentCommand;
}

void Context::NextCommand()
{
	if (!m_listCommandSet.empty())
	{
		m_strCurrentCommand = m_listCommandSet.front();
		m_listCommandSet.pop_front();
	}
	else
	{
		m_strCurrentCommand = "";
	}
}

int Context::GetLoopNumber()
{
	int number = 0;
	number = atoi(m_strCurrentCommand.c_str());
	return number;
}

void Context::SplitString(const std::string& strText)
{
	std::string::size_type pos1 = 0;
	std::string::size_type pos2;

	while ((pos2 = strText.find(" ", pos1)) != std::string::npos)
	{
		m_listCommandSet.push_back(strText.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
	}

	// 最后一个
	if (pos1 != strText.length())
	{
		m_listCommandSet.push_back(strText.substr(pos1));
	}
}


Expression::Expression()
{

}

Expression::~Expression()
{

}

CommandSet::CommandSet()
{

}

CommandSet::~CommandSet()
{
	std::list<Expression*>::iterator it = m_listCommands.begin();
	for (; it != m_listCommands.end(); ++it)
	{
		SAFE_DELETE(*it);
	}
}

void CommandSet::interpret(Context* context)
{
	while (true)
	{
		if (context->GetCurrentCommand() == "")	// context为空
		{
			break;
		}
		else if (context->GetCurrentCommand() == "END")	// 不解释END
		{
			context->NextCommand();
			break;
		}
		else
		{
			Expression* pCommand = new Command();
			pCommand->interpret(context);
			m_listCommands.push_back(pCommand);
		}
	}
}

void CommandSet::execute()
{
	std::list<Expression*>::iterator it = m_listCommands.begin();
	for (; it != m_listCommands.end(); ++it)
	{
		(*it)->execute();
	}
}

Command::Command() : m_pCommand(nullptr)
{

}

Command::~Command()
{
	SAFE_DELETE(m_pCommand);
}

void Command::interpret(Context* context)
{
	if (context->GetCurrentCommand() == "LOOP")
	{
		m_pCommand = new LoopCommand();
		m_pCommand->interpret(context);
	}
	else
	{
		m_pCommand = new PrimitiveCommand();
		m_pCommand->interpret(context);
	}
}

void Command::execute()
{
	m_pCommand->execute();
}

LoopCommand::LoopCommand() : m_pExpression(nullptr)
{

}

LoopCommand::~LoopCommand()
{
	SAFE_DELETE(m_pExpression);
}

void LoopCommand::interpret(Context* context)
{
	context->NextCommand(); // 跳过"LOOP"
	m_nNumber = context->GetLoopNumber();
	context->NextCommand();	// 跳过number

	m_pExpression = new CommandSet();
	m_pExpression->interpret(context);
}

void LoopCommand::execute()
{
	for (int i = 0; i < m_nNumber; ++i)
	{
		m_pExpression->execute();
	}
}


PrimitiveCommand::PrimitiveCommand()
{

}

PrimitiveCommand::~PrimitiveCommand()
{

}

void PrimitiveCommand::interpret(Context* context)
{
	m_strCommand = context->GetCurrentCommand();
	context->NextCommand();

	if (m_strCommand == "PRINT")
	{
		m_strText = context->GetCurrentCommand();
		context->NextCommand();
	}
}

void PrimitiveCommand::execute()
{
	if (m_strCommand == "PRINT")
	{
		std::cout << m_strText;
	}
	else if (m_strCommand == "SPACE")
	{
		std::cout << " ";
	}
	else if (m_strCommand == "BREAK")
	{
		std::cout << std::endl;
	}
}



int main()
{
	std::string text = "LOOP 2 PRINT 杨过 SPACE SPACE PRINT 小龙女 BREAK END PRINT 郭靖 SPACE SPACE PRINT 黄蓉";
	Context* pContext = new Context(text);

	Expression* pExpression = new CommandSet();
	pExpression->interpret(pContext);
	pExpression->execute();

	return 0;
}