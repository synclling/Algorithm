#pragma once

class Subsystem1;
class Subsystem2;

class Facade
{
public:
	Facade();
	~Facade();

	void OperationWrapper();

private:
	Subsystem1* m_pSubsystem1;
	Subsystem2* m_pSubsystem2;
};