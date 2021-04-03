#pragma once

#include "Telegram.h"

class GameEntity
{
private:
	int m_ID;
	static int m_iNextValidID;
	void SetID(int val);
public:
	GameEntity(int id) { SetID(id); }
	virtual ~GameEntity(){}
	virtual bool HandleMessage(const Telegram& msg) = 0;
	int ID()const { return m_ID; }

};