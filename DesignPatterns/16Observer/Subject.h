#pragma once
#include <string>
#include <list>

class Observer;

class Subject
{
protected:
	Subject();

public:
	virtual ~Subject();

	virtual void Attach(Observer* pObserver);
	virtual void Detach(Observer* pObserver);
	virtual void Notify();

	virtual std::string GetState() = 0;
	virtual void SetState(const std::string& str) = 0;

private:
	std::list<Observer*> m_listObserver;
};

class ConcreteSubject : public Subject
{
public:
	ConcreteSubject();
	~ConcreteSubject();

	std::string GetState();
	void SetState(const std::string& strState);

private:
	std::string m_strState;
};