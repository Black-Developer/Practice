#include <iostream>
#include "Component.h"
#include "Object.h"
using namespace std;

int main()
{
	Object* tank = new Object("tank");
	tank->setPosition(10.0f, 0.0f, 0.0f);

	Object* wheel = new Object("wheel");
	wheel->setPosition(0.0f, 5.0f, 0.0f);
	tank->addChild(wheel);

	Object* head = new Object("head");
	head->setPosition(0.0f, 0.0f, 7.0f);
	tank->addChild(head);

	tank->translate(5.0f, 0.0f, 0.0f);
		

	tank->list();
}