#pragma once

#include "StateMachine.h"
#include "State.h"

class Miner;

class MinerGlobalState : public State<Miner>
{
private:
	MinerGlobalState() {}

public:
	static MinerGlobalState* Instance();

	virtual void Enter(Miner* miner) {}
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner) {}
	bool OnMessage(Miner* pMiner, const Telegram& msg);
};

class SaveMoney : public State<Miner>
{
private:
	SaveMoney() {}
public:
	static SaveMoney* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
	bool OnMessage(Miner* pMiner, const Telegram& msg);
};


class GoldMining : public State<Miner>
{
private:
	GoldMining() {}

public:
	static GoldMining* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
	bool OnMessage(Miner* pMiner, const Telegram& msg);
};

class RestInHome : public State<Miner>
{
private:
	RestInHome() {}
	RestInHome(const  RestInHome&);

public:
	static RestInHome* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
	bool OnMessage(Miner* pMiner, const Telegram& msg);
};

class VisitSaloon : public State<Miner>
{
private:
	VisitSaloon() {}
public:
	static VisitSaloon* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
	bool OnMessage(Miner* pMiner, const Telegram& msg);
};

class VisitToilet : public State<Miner>
{
private:
	VisitToilet() {}

public:
	static VisitToilet* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);

	virtual bool OnMessage(Miner* entitiy, const Telegram& msg) { return false; }
};