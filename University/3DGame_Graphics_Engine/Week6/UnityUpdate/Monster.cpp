#include <iostream>
#include "Monster.h"

using namespace std;

void Monster::Update()
{
	// This is Unity Update Function
	// 1 second 1 process
	return;
}
void Monster::FixedUpdate()
{
	Object::FixedUpdate();
	// This is Unity FixedUpdate Function
	// 3 second 1 process

	cout << "I' M MONSTER" << endl;
	return;
}