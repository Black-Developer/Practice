#include "MessageDispatcher.h"
#include "Locations.h"
#include "MessageTypes.h"
#include <iostream>
#include "EntityManager.h"

using namespace std;



MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher Instance;
	return &Instance;
}


void MessageDispatcher::Discharge(GameEntity* pReceiver, const Telegram& telegram)
{
	if (!pReceiver->HandleMessage(telegram))
	{
		cout << "Nothing to do" << endl;
	}
}

void MessageDispatcher::Dispatch_Message(int sender, int receiver, int msg)
{
	GameEntity* pSender = EntityMgr->GetEntityFromID(sender);
	GameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

	if (pReceiver == NULL)
	{
		cout << "WARNING !! RECEIVER IS NULL" << endl;

		return;
	}
	Telegram telegram(sender, receiver, msg);
	Discharge(pReceiver, telegram);
}