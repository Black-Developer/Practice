#pragma once

struct Telegram;

template <class entitiy_type>

class State
{
public:
	State() {}
	virtual ~State() {}

	virtual void Enter(entitiy_type* miner) = 0;
	virtual void Execute(entitiy_type* mier) = 0;
	virtual void Exit(entitiy_type* miner) = 0;
	virtual bool OnMessage(entitiy_type*, const Telegram&) = 0;
};