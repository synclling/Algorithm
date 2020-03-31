#pragma once

class Subject
{
protected:
	Subject();

public:
	~Subject();

	virtual void Request() = 0;
};

class ConcreteSubject : public Subject
{
public:
	ConcreteSubject();
	~ConcreteSubject();

	void Request();
};