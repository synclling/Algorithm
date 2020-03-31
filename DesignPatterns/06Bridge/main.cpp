// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Abstraction.h"
#include "AbstractionImp.h"

int main()
{
    std::cout << "Hello World!\n"; 
	AbstractionImp* imp = new ConcreteAbstractionImpA();

	Abstraction* abs = new RefinedAbstraction(imp);
	abs->Operation();

	SAFE_DELETE(imp);
	SAFE_DELETE(abs);

	return 0;
}

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
 * Bridge模式的本质是将抽象和行为分开，对应两个接口
 */

/*

// 行为接口，例如加奶或不加奶
class CoffeeImp
{
public:
	virtual ~CoffeeImp() {}

	virtual void Operation() = 0;

protected:
	CoffeeImp() {}
};

class CoffeeImpA : public CoffeeImp
{
public:
	CoffeeImpA() {}
	~CoffeeImpA() {}

	virtual void Operation()
	{
		std::cout << "咖啡加奶" << std::endl;
	}
};

class CoffeeImpB : public CoffeeImp
{
public:
	CoffeeImpB() {}
	~CoffeeImpB() {}

	virtual void Operation()
	{
		std::cout << "咖啡不加奶" << std::endl;
	}
};

// 抽象接口，咖啡的大小
class Coffee
{
public:
	virtual ~Coffee() {}

	virtual void Operation() = 0;

protected:
	Coffee() {}
};

class MediumCoffee : public Coffee
{
public:
	MediumCoffee(CoffeeImp* pCoffeeImp)
	{
		m_pCoffeeImp = pCoffeeImp;
	}
	~MediumCoffee() {}

	void Operation()
	{
		m_pCoffeeImp->Operation();
	}

private:
	CoffeeImp* m_pCoffeeImp;
};

*/