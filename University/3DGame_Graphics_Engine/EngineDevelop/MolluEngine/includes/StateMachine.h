#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "State.h"

template <class entity_type>
class StateMachine
{
private:
	entity_type* m_pCurrentState;
	entity_type* m_pPreviousState;
	entity_type* m_pGlobalState;

public:
	entity_type* GetCurrentState() const { return m_pCurrentState; }
	entity_type* GetGlobalState() const { return m_pGlobalState; }
	entity_type* GetPreviousState() const { return m_pPreviousState; }

	void SetCurrentState(entity_type* state)
	{
		m_pCurrentState = state;
	}
	void SetGlobalState(entity_type* state)
	{
		m_pGlobalState = state;
	}
	void SetPreviousState(entity_type* state)
	{
		m_pPreviousState = state;
	}
	StateMachine() :
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr),
		m_pGlobalState(nullptr) {}
	virtual ~StateMachine() {}

	void Update() const
	{
		if (m_pGlobalState)
			m_pGlobalState->Execute();
		if (m_pCurrentState)
			m_pCurrentState->Execute();
	};
	void ChangeState(entity_type* pNewState)
	{
		m_pPreviousState = m_pCurrentState;
		m_pCurrentState->Exit();
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter();
	}

	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}
};

#endif // !__STATEMACHINE_H__