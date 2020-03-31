#include "pch.h"
#include "Subject.h"

Subject::Subject()
{

}

Subject::~Subject()
{

}


ConcreteSubject::ConcreteSubject()
{

}

ConcreteSubject::~ConcreteSubject()
{

}

void ConcreteSubject::Request()
{
	std::cout << "ConcreteSubject Request..." << std::endl;
}