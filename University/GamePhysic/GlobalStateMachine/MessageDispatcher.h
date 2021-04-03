#pragma once

#include "Telegram.h"
#include "GameEntity.h"

class GameEntity;

#define Dispatch MessageDispatcher::Instance()

class MessageDispatcher
{
private:
	void Discharge(GameEntity* pReceiver, const Telegram& msg);
	MessageDispatcher() {}
	//MessageDispatcher(const MessageDispatcher&);
public:
	static MessageDispatcher* Instance();

	void Dispatch_Message(int sender, int receiver, int msg);
	~MessageDispatcher() {}

};