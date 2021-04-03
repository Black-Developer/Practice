#pragma once

#include "GameEntity.h"
#include "StateMachine.h"
#include "NPCOwendStates.h"

class NPC : public GameEntity
{
private:
public:
	StateMachine<NPC>* m_pStateMachine;

	NPC(int id) :GameEntity(id)
	{
		m_pStateMachine = new StateMachine<NPC>(this);
		m_pStateMachine->SetCurrentState(idle::Instance());
	}
	void Update();
	virtual bool HandleMessage(const Telegram& msg);
	

};