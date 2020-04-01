#pragma once

class State;

class Context
{
	friend class State;	//将State声明为友元类以便在State的具体类中调用ChangeState

public:
	Context(State* pState);
	~Context();

	void OperationChangeState();

protected:
	bool ChangeState(State* pState);

private:
	State* m_pState;	//维护一个具体的状态类，定义当前的状态
};
