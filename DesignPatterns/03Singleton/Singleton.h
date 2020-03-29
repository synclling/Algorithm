#pragma once

/********************************************/
/*				饿汉模式的简单版本				*/
/********************************************/
class Singleton1
{
private:
	Singleton1();
	Singleton1(const Singleton1 &obj) = delete; //删除默认拷贝构造函数，禁止默认拷贝
	Singleton1 &operator=(const Singleton1 &obj) = delete; //删除赋值构造函数，禁止默认赋值

public:
	~Singleton1();

	static Singleton1* GetInstance()
	{
		return &m_instance;
	}

private:
	static Singleton1 m_instance;
};



/********************************************/
/*			饿汉模式的增强版本(Boost实现)		*/
/********************************************/
class Singleton2
{
private:
	Singleton2();
	Singleton2(const Singleton2 &obj) = delete; //删除默认拷贝构造函数，禁止默认拷贝
	Singleton2 &operator=(const Singleton2 &obj) = delete; //删除赋值构造函数，禁止默认赋值

public:
	~Singleton2();

	static Singleton2* GetInstance()
	{
		static Singleton2 instance;
		return &instance;
	}

protected:
	//内嵌一个工具类，完成第一次调用GetInstance()工作
	class Object_Creator
	{
	public:
		Object_Creator()
		{
			Singleton2::GetInstance();
		}
	};

	static Object_Creator object_creator;
};



/********************************************/
/*					懒汉模式					*/
/********************************************/
class Singleton3
{
private:
	Singleton3();
	Singleton3(const Singleton3 &obj) = delete; //删除默认拷贝构造函数，禁止默认拷贝
	Singleton3 &operator=(const Singleton3 &obj) = delete; //删除赋值构造函数，禁止默认赋值

public:
	~Singleton3();

	static Singleton3* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			//Lock(); 加锁
			if (m_pInstance == nullptr)
			{
				m_pInstance = new Singleton3();
			}
			//UnLock(); 解锁
		}

		return m_pInstance;
	}

protected:
	//内嵌一个垃圾回收类
	class Garbo
	{
	public:
		~Garbo()
		{
			if (Singleton3::m_pInstance != nullptr)
			{
				delete Singleton3::m_pInstance;
				Singleton3::m_pInstance = nullptr;
			}
		}
	};

	static Garbo garbo;

private:
	static Singleton3* m_pInstance;
};
