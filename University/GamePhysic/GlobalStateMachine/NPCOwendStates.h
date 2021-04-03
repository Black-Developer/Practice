#pragma once

#include "State.h"

class NPC;

class idle : public State<NPC>
{
private:
	idle() {}
public:
	static idle* Instance();
	virtual void Enter(NPC* npc) {}
	virtual void Execute(NPC* npc);
	virtual void Exit(NPC* npc) {}
	virtual bool OnMessage(NPC* npc, const Telegram& msg);

};