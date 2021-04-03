#include "NPCOwendStates.h"
#include "NPC.h"

#include "MessageTypes.h"
#include "MessageDispatcher.h"

#include "NpcNames.h"

#include <iostream>

using namespace std;

idle* idle::Instance()
{
	static idle Instance;

	return &Instance;
}

void idle::Execute(NPC* npc)
{
}

bool idle::OnMessage(NPC* npc, const Telegram& msg)
{
	switch (msg.Msg)
	{
	case Msg_Tissue_Plsase:
		cout << "NPC : No TISSUE!" << endl;
		Dispatch->Dispatch_Message(npc->ID(), ent_Miner_Steve, Msg_OK);
		break;
	}
	return true;
}