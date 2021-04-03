#include "MinerOwnedStates.h"
#include <iostream>

using namespace std;


Mininggold* Mininggold::Instance()
{
	static Mininggold instance;

	return &instance;
}

void Mininggold::Enter(Miner* miner)
{
	cout << "Mining Gold in the Mine" << endl;
}

Savegold* Savegold::Instance()
{
	static Savegold instance;

	return &instance;
}
void Savegold::Enter(Miner* miner)
{
	cout << "Save Gold in bank" << endl;
}

Thirstyreduce* Thirstyreduce::Instance()
{
	static Thirstyreduce instance;

	return &instance;
}

void Thirstyreduce::Enter(Miner* miner)
{
	cout << "Thirsty Reduce" << endl;
}

Restathome* Restathome::Instance()
{
	static Restathome instance;

	return &instance;
}

void Restathome::Enter(Miner* miner)
{
	cout << "Rest in home" << endl;
}

Restroom* Restroom::Instance()
{
	static Restroom instance;

	return &instance;
}
void Restroom::Enter(Miner* miner)
{
	cout << "Go to restroom" << endl;
}