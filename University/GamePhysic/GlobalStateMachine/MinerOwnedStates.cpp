#include "MinerOwnedStates.h"
#include "RandomEventManager.h"
#include "Miner.h"
#include <iostream>

#include "MessageTypes.h"
#include "MessageDispatcher.h"

#include "NpcNames.h"

using namespace std;



MinerGlobalState* MinerGlobalState::Instance()
{
	static MinerGlobalState Instance;

	return &Instance;
}


void  MinerGlobalState::Execute(Miner* miner)
{
	if (RandomEventManager::GetInstance()->Event_Generator(100) <= 50)
	{
		miner->GetFSM()->ChangeState(VisitToilet::Instance());
	}
}
bool MinerGlobalState::OnMessage(Miner* pMiner, const Telegram& msg)
{
	switch (msg.Msg)
	{
	case Msg_OK:
		cout << "MINER : NOOOOOOOOOO!" << endl << endl;
		return true;
	}
	return false;
}


// 돈을 저장하러 은행에 방문함
SaveMoney* SaveMoney::Instance()
{
	static SaveMoney Instance;
	return &Instance;
}

void SaveMoney::Enter(Miner* miner)
{
	cout << "Enter Bank" << endl << endl;
}


void SaveMoney::Execute(Miner* miner)
{
	if (miner->GetInput() == 2)
	{
	cout << "MINER GoldMining" << endl;
		miner->GetFSM()->ChangeState(GoldMining::Instance());
		miner->ChangeLocation(goldmine);
	}
	else if (miner->GetInput() == 3)
	{
		cout << "MINER Rest In Home" << endl;
		miner->GetFSM()->ChangeState(RestInHome::Instance());
		miner->ChangeLocation(shack);
	}
}
void SaveMoney::Exit(Miner* miner)
{
	cout << "Exit Bank" << endl;
}
bool SaveMoney::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}


// 금덩이를 광산에서 채굴함
GoldMining* GoldMining::Instance()
{
	static GoldMining Instance;
	return &Instance;
}

void GoldMining::Enter(Miner* miner)
{
	cout << "Enter Mine" << endl << endl;
}
void GoldMining::Execute(Miner* miner)
{
	if (miner->GetInput() == 1)
	{
		cout << "MINER Save Money In Bank" << endl;
		miner->GetFSM()->ChangeState(SaveMoney::Instance());
		miner->ChangeLocation(bank);
	}
	else if (miner->GetInput() == 5)
	{
		cout << "MINER Quenching Thirst" << endl;
		miner->GetFSM()->ChangeState(VisitSaloon::Instance());
		miner->ChangeLocation(saloon);
	}
}
void GoldMining::Exit(Miner* miner)
{
	cout << "Exit Mine" << endl;
}
bool GoldMining::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}

// 갈증을 해소함
VisitSaloon* VisitSaloon::Instance()
{
	static VisitSaloon Instance;
	return &Instance;
}

void VisitSaloon::Enter(Miner* miner)
{
	cout << "Enter Saloon" << endl << endl;
}
void VisitSaloon::Execute(Miner* miner)
{
	if (miner->GetInput() == 6)
	{
		cout << "MINER GoldMining" << endl;
		miner->GetFSM()->ChangeState(GoldMining::Instance());
		miner->ChangeLocation(goldmine);
	}
}
void VisitSaloon::Exit(Miner* miner)
{
	cout << "Exit Saloon" << endl;
}
bool VisitSaloon::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}


// 휴식을 취함
RestInHome* RestInHome::Instance()
{
	static RestInHome Instance;
	return &Instance;
}

void RestInHome::Enter(Miner* miner)
{
	cout << "Enter Shack" << endl << endl;
}
void RestInHome::Execute(Miner* miner)
{
	if (miner->GetInput() == 4)
	{
		cout << "MINER GoldMining" << endl;
		miner->GetFSM()->ChangeState(GoldMining::Instance());
		miner->ChangeLocation(goldmine);
	}
}
void RestInHome::Exit(Miner* miner)
{
	cout << "Exit Shack" << endl;
}
bool RestInHome::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}

// 화장실 방문
VisitToilet* VisitToilet::Instance()
{
	static VisitToilet Instance;
	return &Instance;
}

void VisitToilet::Enter(Miner* miner)
{
	cout << "Enter Toilet" << endl << endl;
}

void VisitToilet::Execute(Miner* miner)
{
	cout << "Miner Visit Toillet" << endl;

	//if (rand() % 100 < 50)
	//{
		Dispatch->Dispatch_Message(miner->ID(), ent_Tissue_Taker, Msg_Tissue_Plsase);
	//}

	Sleep(1000);
	miner->GetFSM()->RevertToPreviousState();
}

void VisitToilet::Exit(Miner* miner)
{
	cout << "Exit Toilet" << endl;
}