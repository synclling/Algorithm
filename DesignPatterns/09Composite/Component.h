#pragma once

/*
 *	Component������࣬Ϊ������֮��ĵݹ�����ṩ�˽���İ취������Ҫ��Ϊ���������ࣺ
 *		1.LeafҶ�ӽ�㣬�����������������
 *		2.Composite֦��㣬�������������
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
