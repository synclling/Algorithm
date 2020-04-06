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
 *   解释表达式'LOOP 3 PRINT 杨过 SPACE SPACE PRINT 小龙女 ENTER END PRINT 郭靖 SPACE SPACE PRINT 黄蓉'
 *   输出：
 *       杨过  小龙女
 *       杨过  小龙女
 *       杨过  小龙女
 *       郭靖  黄蓉
 *
 */

#include "pch.h"
#include <string>
#include <list>

class Context
{
public:
	Context(const std::string& strText);
	~Context();

	std::string GetCurrentCommand();
	void NextCommand();
	int GetLoopNumber();

protected:
	void SplitString(const std::string& strText, const std::string c = " ");

private:
	std::string m_strCurrentCommand;
	std::list<std::string> m_listCommand;
};

// 抽象表达式
class AbstractExpression
{
protected:
	AbstractExpression();

public:
	virtual ~AbstractExpression();

	virtual void interpret(Context* context) = 0;
	virtual void execute() = 0;
};


// 代码块(非终结符表达式)，解释context并生成每条指令
class CodeBlock : public AbstractExpression
{
public:
	CodeBlock();
	~CodeBlock();

	void interpret(Context* context);
	void execute();

private:
	std::list<AbstractExpression*> m_listCodeBlock;
};


// 单条指令(非终结符表达式)，解释生成LoopCommand或PrimitiveCommand
class CommandExpression : public AbstractExpression
{
public:
	CommandExpression();
	~CommandExpression();

	void interpret(Context* context);
	void execute();

private:
	AbstractExpression* m_pCommand;
};


// 循环指令(非终结符表达式)，解释执行循环指令
class LoopCommand : public AbstractExpression
{
public:
	LoopCommand();
	~LoopCommand();

	void interpret(Context* context);
	void execute();

private:
	int m_nNumber;						// 循环次数
	AbstractExpression* m_pCodeBlock;	// 循环主体
};


// 元指令(终结符表达式)，解释执行基本指令
class PrimitiveCommand : public AbstractExpression
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



//------------------------------------------------------


Context::Context(const std::string& strText)
{
	SplitString(strText);
	NextCommand();	//指向第一条指令
}

Context::~Context()
{

}

std::string Context::GetCurrentCommand()
{
	return m_strCurrentCommand;
}

void Context::NextCommand()
{
	if (!m_listCommand.empty())
	{
		m_strCurrentCommand = m_listCommand.front();
		m_listCommand.pop_front();
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

void Context::SplitString(const std::string& strText, const std::string c)
{
	std::string::size_type pos1 = 0;
	std::string::size_type pos2;

	while ((pos2 = strText.find(c, pos1)) != std::string::npos)
	{
		m_listCommand.push_back(strText.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
	}

	// 最后一部分
	if (pos1 != strText.size())
	{
		m_listCommand.push_back(strText.substr(pos1));
	}
}


AbstractExpression::AbstractExpression()
{

}

AbstractExpression::~AbstractExpression()
{

}


CodeBlock::CodeBlock()
{

}

CodeBlock::~CodeBlock()
{
	std::list<AbstractExpression*>::iterator it = m_listCodeBlock.begin();
	for (; it != m_listCodeBlock.end(); ++it)
	{
		SAFE_DELETE(*it);
	}
}

void CodeBlock::interpret(Context* context)
{
	while (true)
	{
		if (context->GetCurrentCommand() == "") // context为空
		{
			break;
		}
		else if (context->GetCurrentCommand() == "END") // 不解释END
		{
			context->NextCommand();
			break;
		}
		else
		{
			// 生成一条指令
			AbstractExpression* pCommandExpression = new CommandExpression();
			pCommandExpression->interpret(context);

			m_listCodeBlock.push_back(pCommandExpression);
		}
	}
}

void CodeBlock::execute()
{
	// 执行每条指令
	std::list<AbstractExpression*>::iterator it = m_listCodeBlock.begin();
	for (; it != m_listCodeBlock.end(); ++it)
	{
		(*it)->execute();
	}
}


CommandExpression::CommandExpression() : m_pCommand(nullptr)
{

}

CommandExpression::~CommandExpression()
{
	SAFE_DELETE(m_pCommand);
}

void CommandExpression::interpret(Context* context)
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

void CommandExpression::execute()
{
	m_pCommand->execute();
}


LoopCommand::LoopCommand() : m_pCodeBlock(nullptr)
{

}

LoopCommand::~LoopCommand()
{
	SAFE_DELETE(m_pCodeBlock);
}

void LoopCommand::interpret(Context* context)
{
	context->NextCommand();	// 跳过LOOP
	m_nNumber = context->GetLoopNumber();
	context->NextCommand();	// 跳过Number

	// 生成循环主体
	m_pCodeBlock = new CodeBlock();
	m_pCodeBlock->interpret(context);
}

void LoopCommand::execute()
{
	for (int i = 0; i < m_nNumber; ++i)
	{
		m_pCodeBlock->execute();
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
	else if (m_strCommand == "ENTER")
	{
		std::cout << std::endl;
	}
}


int main()
{
	std::string text = "LOOP 3 PRINT 杨过 SPACE SPACE PRINT 小龙女 ENTER END PRINT 郭靖 SPACE SPACE PRINT 黄蓉";
	Context* pContext = new Context(text);

	AbstractExpression* pCodeBlock = new CodeBlock();
	pCodeBlock->interpret(pContext);
	pCodeBlock->execute();

	SAFE_DELETE(pCodeBlock);
	SAFE_DELETE(pContext);

	return 0;
}