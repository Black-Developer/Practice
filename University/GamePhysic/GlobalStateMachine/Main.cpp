#include <iostream>
#include <Windows.h>
#include "Miner.h"
#include "RandomEventManager.h"
#include "EntityManager.h"
#include "NpcNames.h"
#include "NPC.h"

using namespace std;

void Update(Miner *miner);

int event_Number;

int main()
{
	Miner *miner = new Miner(ent_Miner_Steve);
	NPC* npc = new NPC(ent_Tissue_Taker);

	EntityMgr->RegisterEntity(miner);
	EntityMgr->RegisterEntity(npc);

	Update(miner);


	return 0;
}

void Update(Miner *miner)
{
	while (true)
	{
		event_Number = RandomEventManager::GetInstance()->Event_Generator(6);
		miner->SetInput(event_Number);
		
		switch (event_Number)
		{
		case 1:
		{
			if (miner->Location() == location_type::goldmine) // 현재 위치와 이동하려는 위치가 같다면 Update 실행
			{
				miner->Update(event_Number);
			}
		}break;
		case 2:
		{
			if (miner->Location() == location_type::bank)
			{
				miner->Update(event_Number);
			}

		}break;
		case 3:
		{
			if (miner->Location() == location_type::bank)
			{
				miner->Update(event_Number);
			}
		}break;
		case 4:
		{		
			if (miner->Location() == location_type::shack)
			{
				miner->Update(event_Number);
			}
		}break;
		case 5:
		{
			if (miner->Location() == location_type::goldmine)
			{
				miner->Update(event_Number);
			}
		}break;
		case 6:
		{
			if (miner->Location() == location_type::saloon)
			{
				miner->Update(event_Number);
			}

		}break;
		default:
			break;
		}
		Sleep(1000);

	}
}