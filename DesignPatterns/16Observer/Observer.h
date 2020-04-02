#pragma once
#include <string>

class Subject;

class Observer
{
protected:
	Observer();

public:
	virtual ~Observer();

	virtual void Update() = 0;
	virtual void PrintInfo() = 0;

protected:
	std::string m_strState;
};

class ConcreteObserverA : public Observer
{
public:
	ConcreteObserverA(Subject* pSubject);
	~ConcreteObserverA();

	void Update();
	void PrintInfo();

private:
	Subject* m_pSubject;
};

class ConcreteObserverB : public Observer
{
public:
	ConcreteObserverB(Subject* pSubject);
	~ConcreteObserverB();

	void Update();
	void PrintInfo();

private:
	Subject* m_pSubject;
};
