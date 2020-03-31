#pragma once

class Subject;

class Proxy
{
public:
	Proxy(Subject* pSubject);
	~Proxy();

	void Request();

private:
	Subject* m_pSubject;
};