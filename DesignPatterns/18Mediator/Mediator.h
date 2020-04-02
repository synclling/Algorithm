#pragma once

class Colleague;

class Mediator
{
protected:
	Mediator();

public:
	virtual ~Mediator();

	virtual void DoActionFromAToB() = 0;
	virtual void DoActionFromBToA() = 0;
};

class ConcreteMediator : public Mediator
{
public:
	ConcreteMediator();
	ConcreteMediator(Colleague* pColleagueA, Colleague* pColleagueB);
	~ConcreteMediator();

	void DoActionFromAToB();
	void DoActionFromBToA();

	void IntroColleague(Colleague* pColleagueA, Colleague* pColleagueB);
	void PrintInfo();

	Colleague* GetConcreteColleagueA();
	Colleague* GetConcreteColleagueB();
	void SetConcreteColleagueA(Colleague* pColleagueA);
	void SetConcreteColleagueB(Colleague* pColleagueB);

private:
	Colleague* m_pColleagueA;
	Colleague* m_pColleagueB;
};