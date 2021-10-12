#include <iostream>
#include "Object.h"

using namespace std;

void Object::Update()
{
	// This is Unity Update Function
	// 1 second 1 process

	cout << "Update\t" << m_Name << "\t : " << i << endl;
	i++;
	return;
}
void Object::FixedUpdate()
{
	// This is Unity FixedUpdate Function
// 3 second 1 process

	cout << "FixedUpdate\t" << m_Name << "\t : " << j << endl;
	j++;
	return;
}