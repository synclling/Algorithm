#pragma once
#include <string>

class Mediator;

class Colleague
{
protected:
	Colleague();
	Colleague(Mediator* pMediator);

public:
	virtual ~Colleague();

	virtual void Action() = 0;

	virtual std::string GetState() = 0;
	virtual void SetState(const std::string& strState) = 0;

protected:
	Mediator* m_pMediator;
};

class ConcreteColleagueA : public Colleague
{
public:
	ConcreteColleagueA();
	ConcreteColleagueA(Mediator* pMediator);
	~ConcreteColleagueA();

	void Action();

	std::string GetState();
	void SetState(const std::string& strState);

private:
	std::string m_strState;
};

class ConcreteColleagueB : public Colleague
{
public:
	ConcreteColleagueB();
	ConcreteColleagueB(Mediator* pMediator);
	~ConcreteColleagueB();

	void Action();

	std::string GetState();
	void SetState(const std::string& strState);

private:
	std::string m_strState;
};