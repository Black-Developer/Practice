#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "State.h"

class StateMachine
{
private:
	State* m_pCurrentState;
	State* m_pPreviousState;
	State* m_pGlobalState;

public:
	State* GetCurrentState() const { return m_pCurrentState; }
	State* GetGlobalState() const { return m_pGlobalState; }
	State* GetPreviousState() const { return m_pPreviousState; }

	void SetCurrentState(State* state);
	void SetGlobalState(State* state);
	void SetPreviousState(State* state);
	StateMachine() :
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr),
		m_pGlobalState(nullptr) {}
	virtual ~StateMachine() {}

	void Update() const;
	void ChangeState(State* pNewState);

	void RevertToPreviousState();
};

#endif // !__STATEMACHINE_H__
