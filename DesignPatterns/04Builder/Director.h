#pragma once

class Builder;

class Director
{
public:
	Director(Builder* pBuilder);
	~Director();

	void Construct();

private:
	Builder* m_pBuilder;
};

