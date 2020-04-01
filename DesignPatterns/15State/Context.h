#pragma once

class State;

class Context
{
	friend class State;	//��State����Ϊ��Ԫ���Ա���State�ľ������е���ChangeState

public:
	Context(State* pState);
	~Context();

	void OperationChangeState();

protected:
	bool ChangeState(State* pState);

private:
	State* m_pState;	//ά��һ�������״̬�࣬���嵱ǰ��״̬
};
