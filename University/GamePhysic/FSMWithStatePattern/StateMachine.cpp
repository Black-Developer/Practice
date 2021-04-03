#include "StateMachine.h"

void StateMachine::ChangeState(State* new_state)
{
	m_pCurrentState->Exit(m_pMiner);

	m_pCurrentState = new_state;

	m_pCurrentState->Enter(m_pMiner);
}