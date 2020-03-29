#include "pch.h"
#include "Singleton.h"

Singleton1 Singleton1::m_instance;//维护一个静态全局变量

Singleton1::Singleton1()
{
}


Singleton1::~Singleton1()
{
}


Singleton2::Object_Creator Singleton2::object_creator;

Singleton2::Singleton2()
{
}


Singleton2::~Singleton2()
{
}


Singleton3::Garbo Singleton3::garbo;
Singleton3* Singleton3::m_pInstance = nullptr;

Singleton3::Singleton3()
{
}


Singleton3::~Singleton3()
{
}