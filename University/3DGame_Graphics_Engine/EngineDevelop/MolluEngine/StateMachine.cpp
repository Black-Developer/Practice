#include "StateMachine.h"



void StateMachine::SetCurrentState(State* state)
{
	m_pCurrentState = state;
}

void StateMachine::SetGlobalState(State* state)
{
	m_pGlobalState = state;
}

void StateMachine::SetPreviousState(State* state)
{
	m_pPreviousState = state;
}

void StateMachine::Update() const
{
	if (m_pGlobalState)
		m_pGlobalState->Execute();
	if (m_pCurrentState)
		m_pCurrentState->Execute();
}

void StateMachine::ChangeState(State* pNewState)
{
	m_pPreviousState = m_pCurrentState;

	m_pCurrentState->Exit();
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter();
}

void StateMachine::RevertToPreviousState()
{
	ChangeState(m_pPreviousState);
}