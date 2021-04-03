#pragma once

#include "Locations.h"
#include "MinerOwnedStates.h"
#include "StateMachine.h"
#include "GameEntity.h"

class Miner : public GameEntity {
private:
	
	location_type m_Location;
	
	StateMachine<Miner>* m_pStateMachine;

	int input;

public:
	Miner(int id) :m_Location(shack), GameEntity(id), input(0)
	{
		m_pStateMachine = new StateMachine<Miner>(this);
		m_pStateMachine->SetCurrentState(RestInHome::Instance());
		m_pStateMachine->SetGlobalState(MinerGlobalState::Instance());
	}
	~Miner() { delete m_pStateMachine; }


	void SetInput(int num) { input = num; }
	int GetInput() { return this->input; }
	void Update(int);
	virtual bool HandleMessage(const Telegram& msg);

	StateMachine<Miner>* GetFSM()const { return m_pStateMachine; }
	location_type Location() const { return m_Location; }
	void ChangeLocation(const location_type locate) { m_Location = locate; }
};