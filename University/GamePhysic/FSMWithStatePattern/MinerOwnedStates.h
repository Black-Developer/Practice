#pragma once
#include "State.h"

class Miner;

class Mininggold : public State
{
public:
	static Mininggold* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner) {}
	virtual void Exit(Miner* miner) {}
};
class Savegold : public State
{
public:
	static Savegold* Instance();
	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner) {}
	virtual void Exit(Miner* miner) {}
};
class Thirstyreduce : public State
{
public:
	static Thirstyreduce* Instance();
	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner) {}
	virtual void Exit(Miner* miner) {}
};
class Restathome : public State
{
public:
	static Restathome* Instance();
	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner) {}
	virtual void Exit(Miner* miner) {}
};