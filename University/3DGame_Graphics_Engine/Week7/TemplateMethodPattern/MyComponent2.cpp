#include <iostream>
#include "MyComponent2.h"

MyComponent2::MyComponent2(){}

MyComponent2::~MyComponent2() {}
void MyComponent2::Start()
{
	std::cout << "MyComponent2";
}
void MyComponent2::FixedUpdate()
{
	std::cout << "MyComponent2";
}