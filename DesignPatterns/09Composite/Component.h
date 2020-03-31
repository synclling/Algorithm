#pragma once

/*
 *	Component抽象基类，为解决组件之间的递归组合提供了解决的办法，它主要分为两个派生类：
 *		1.Leaf叶子结点，即不含有子组件的类
 *		2.Composite枝结点，含有子组件的类
 */

class Component
{
public:
	Component();
	virtual ~Component();

public:
	virtual void Operation() = 0;

	virtual void Add(Component* obj);
	virtual void Remove(Component* obj);
	virtual Component* GetChild(int index);
};
