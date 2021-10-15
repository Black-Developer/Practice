#include <iostream>
#include "GameObject.h"
#include "Component.h"
#include "MyComponent.h"
#include "MyComponent2.h"

using namespace std;

int main()
{
	GameObject* obj1 = new GameObject();
	obj1->addComponent(new MyComponent());
	obj1->addComponent(new MyComponent2());

	obj1->loop();

	delete obj1;

	return 0;
}