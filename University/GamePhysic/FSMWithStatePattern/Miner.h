#pragma once
#include "State.h"
#include "Locations.h"
#include "StateMachine.h"


class Miner
{
public:
	Miner() { m_Location = location_type::goldmine; m_pStateMachine->SetCurrentState(Mininggold::Instance()); }
	~Miner() {}

	StateMachine* GetFSM() { return m_pStateMachine; }
	StateMachine* GetGlobalFSM() { return m_pGlobalStateMachine; }
	void Update(int input);
private:
	location_type m_Location;
	StateMachine* m_pStateMachine = new StateMachine(this);
	StateMachine* m_pGlobalStateMachine = new StateMachine(this);
};