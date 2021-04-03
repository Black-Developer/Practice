#pragma once
#include "MinerOwnedStates.h"

class StateMachine : public Mininggold, public Savegold,public Thirstyreduce,public Restathome
{
public:
	void ChangeState(State* new_state);

	StateMachine(Miner* miner) { m_pMiner = miner; }
	void SetCurrentState(State* s) { m_pCurrentState = s; }
private:
	Miner* m_pMiner;
	State* m_pCurrentState;
	State* m_pPreviousState;
};