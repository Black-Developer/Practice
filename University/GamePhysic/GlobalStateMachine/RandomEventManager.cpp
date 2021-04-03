#include "RandomEventManager.h"


RandomEventManager* RandomEventManager::Instance = NULL;

RandomEventManager* RandomEventManager::GetInstance()
{
	if (!Instance)
	{
		Instance = new RandomEventManager;
	}
	return Instance;
}

int RandomEventManager::Event_Generator(int range)
{
	int result;
	srand((unsigned)time(NULL));
	result = (rand() % range) + 1;

	return result;
}