#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Time.h"
#include "Monster.h"
#include "Player.h"

using namespace std;

void ObjectUpdate();
void ObjectFixedUpdate();
vector<Object*> objectList;

void main()
{
	void (*pUpdate)() = ObjectUpdate;
	void (*pFixedUpdate)() = ObjectFixedUpdate;

	// Create Object
	Player* player = new Player("Player");
	Monster* monster = new Monster("Monster");
	Object* timer = new Object("Timer");
	// Add Object
	objectList.push_back(player);
	objectList.push_back(monster);
	objectList.push_back(timer);

	while (true)
	{
		for (int i = 0; i < objectList.size(); i++)
		{
			Time::instance().getUpdate()->FrameUpdate(pUpdate);
			Time::instance().getFixedUpdate()->FrameUpdate(pFixedUpdate);
			Sleep(100);
			std::cout << std::fixed;
			std::cout.precision(5);
			cout << "Delta Time : " << Time::instance().getDeltaTime() << endl;
			std::cout.unsetf(ios::fixed);
		}
	}
	delete(player);
	delete(monster);
	delete(timer);
	exit(0);
}

void ObjectUpdate()
{
	for (int i = 0; i < objectList.size(); i++)
	{
		objectList.at(i)->Update();
	}
}
void ObjectFixedUpdate()
{
	for (int i = 0; i < objectList.size(); i++)
	{
		objectList.at(i)->FixedUpdate();
	}
}