// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Component.h"
#include "Composite.h"
#include "Leaf.h"

int main()
{
    std::cout << "Hello World!\n"; 

	Leaf* pLeaf = new Leaf();
	pLeaf->Operation();

	Composite* pComposite = new Composite();
	pComposite->Add(pLeaf);
	pComposite->Operation();

	Component* pComponent = pComposite->GetChild(0);
	pComponent->Operation();

	SAFE_DELETE(pComposite);
	SAFE_DELETE(pLeaf);

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

//#include "pch.h"
//#include <string>
//#include <list>
//
//class Company
//{
//public:
//	Company(std::string strName) { m_strName = strName; }
//	virtual ~Company() {}
//
//	virtual void show(int depth) = 0;
//	virtual void Add(Company* obj) {}
//
//protected:
//	std::string m_strName;
//};
//
//class ConcreteCompany : public Company
//{
//public:
//	ConcreteCompany(std::string strName) : Company(strName) {}
//	~ConcreteCompany() {}
//
//	void show(int depth)
//	{
//		for (int i = 0; i < depth; ++i)
//		{
//			std::cout << "-";
//		}
//		std::cout << m_strName << std::endl;
//
//		auto it = m_listCompany.begin();
//		for (; it != m_listCompany.end(); ++it)
//		{
//			(*it)->show(depth + 2);
//		}
//	}
//
//	void Add(Company* obj)
//	{
//		m_listCompany.push_back(obj);
//	}
//
//private:
//	std::list<Company*> m_listCompany;
//};
//
//class FinanceDepartment : public Company
//{
//public:
//	FinanceDepartment(std::string strName) : Company(strName) {}
//	~FinanceDepartment() {}
//
//	void show(int depth)
//	{
//		for (int i = 0; i < depth; ++i)
//		{
//			std::cout << "-";
//		}
//		std::cout << m_strName << std::endl;
//	}
//};
//
//class HRDepartment : public Company
//{
//public:
//	HRDepartment(std::string strName) : Company(strName) {}
//	~HRDepartment() {}
//
//	void show(int depth)
//	{
//		for (int i = 0; i < depth; ++i)
//		{
//			std::cout << "-";
//		}
//		std::cout << m_strName << std::endl;
//	}
//};
//
//int main()
//{
//	Company* pRoot = new ConcreteCompany("总公司");
//	Company* pLeaf1 = new FinanceDepartment("财务部");
//	Company* pLeaf2 = new HRDepartment("人力部");
//	pRoot->Add(pLeaf1);
//	pRoot->Add(pLeaf2);
//
//	Company* pMid1 = new ConcreteCompany("分公司A");
//	Company* pLeaf3 = new FinanceDepartment("财务部");
//	Company* pLeaf4 = new HRDepartment("人力部");
//	pMid1->Add(pLeaf3);
//	pMid1->Add(pLeaf4);
//
//	pRoot->Add(pMid1);
//
//	Company* pMid2 = new ConcreteCompany("分公司B");
//	Company* pLeaf5 = new FinanceDepartment("财务部");
//	Company* pLeaf6 = new HRDepartment("人力部");
//	pMid2->Add(pLeaf3);
//	pMid2->Add(pLeaf4);
//
//	pRoot->Add(pMid2);
//
//	pRoot->show(0);
//
//	SAFE_DELETE(pLeaf1);
//	SAFE_DELETE(pLeaf2);
//	SAFE_DELETE(pLeaf3);
//	SAFE_DELETE(pLeaf4);
//	SAFE_DELETE(pLeaf5);
//	SAFE_DELETE(pLeaf6);
//
//	SAFE_DELETE(pMid1);
//	SAFE_DELETE(pMid2);
//
//	SAFE_DELETE(pRoot);
//
//	return 0;
//}