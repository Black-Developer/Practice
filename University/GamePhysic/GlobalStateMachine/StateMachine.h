#pragma once
#include <Windows.h>
#include "MinerOwnedStates.h"
#include "State.h"

template <class entitiy_type>

class StateMachine
{
private:
	entitiy_type* m_pOwner;
	State<entitiy_type>* m_pCurrentState;
	State<entitiy_type>* m_pPreviousState;
	State<entitiy_type>* m_pGlobalState;

public:
	State<entitiy_type>* CurrentState()	const { return m_pCurrentState; }
	State<entitiy_type>* GlobalState()	const { return m_pGlobalState; }
	State<entitiy_type>* PreviousState()	const { return m_pPreviousState; }

	StateMachine(entitiy_type* owner) :
		m_pOwner(owner),
		m_pCurrentState(NULL),
		m_pPreviousState(NULL),
		m_pGlobalState(NULL) {}

	virtual ~StateMachine() {}

	void SetCurrentState(State<entitiy_type>* s) { m_pCurrentState = s; }
	void SetGlobalState(State<entitiy_type>* s) { m_pGlobalState = s; }
	void SetPreviousState(State<entitiy_type>* s) { m_pGlobalState = s; }

	void Update(int events) const
	{

		if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);

		if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);

	}
	void ChangeState(State<entitiy_type>* pNewState)	// 상태를 새로운 상태로 변경
{
	m_pPreviousState = m_pCurrentState;

	m_pCurrentState->Exit(m_pOwner);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(m_pOwner);
}

	void RevertToPreviousState() // 이전상태로 되돌아가기
	{
		ChangeState(m_pPreviousState);
	}


	bool HandleMessage(const Telegram& msg) const
	{
		if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
		{
			return true;
		}

		if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
		{
			return true;
		}
		return false;

		
	}
};