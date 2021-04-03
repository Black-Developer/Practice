#pragma once
#include <time.h>
#include <stdlib.h>

class RandomEventManager {
private:
	RandomEventManager() {};
	~RandomEventManager() {};
	static RandomEventManager* Instance;
public:
	static RandomEventManager* GetInstance();
	int Event_Generator(int);
};