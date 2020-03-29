#pragma once

/********************************************/
/*				����ģʽ�ļ򵥰汾				*/
/********************************************/
class Singleton1
{
private:
	Singleton1();
	Singleton1(const Singleton1 &obj) = delete; //ɾ��Ĭ�Ͽ������캯������ֹĬ�Ͽ���
	Singleton1 &operator=(const Singleton1 &obj) = delete; //ɾ����ֵ���캯������ֹĬ�ϸ�ֵ

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
/*			����ģʽ����ǿ�汾(Boostʵ��)		*/
/********************************************/
class Singleton2
{
private:
	Singleton2();
	Singleton2(const Singleton2 &obj) = delete; //ɾ��Ĭ�Ͽ������캯������ֹĬ�Ͽ���
	Singleton2 &operator=(const Singleton2 &obj) = delete; //ɾ����ֵ���캯������ֹĬ�ϸ�ֵ

public:
	~Singleton2();

	static Singleton2* GetInstance()
	{
		static Singleton2 instance;
		return &instance;
	}

protected:
	//��Ƕһ�������࣬��ɵ�һ�ε���GetInstance()����
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
/*					����ģʽ					*/
/********************************************/
class Singleton3
{
private:
	Singleton3();
	Singleton3(const Singleton3 &obj) = delete; //ɾ��Ĭ�Ͽ������캯������ֹĬ�Ͽ���
	Singleton3 &operator=(const Singleton3 &obj) = delete; //ɾ����ֵ���캯������ֹĬ�ϸ�ֵ

public:
	~Singleton3();

	static Singleton3* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			//Lock(); ����
			if (m_pInstance == nullptr)
			{
				m_pInstance = new Singleton3();
			}
			//UnLock(); ����
		}

		return m_pInstance;
	}

protected:
	//��Ƕһ������������
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
