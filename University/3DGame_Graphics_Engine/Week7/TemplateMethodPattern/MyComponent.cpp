#include <iostream>
#include "MyComponent.h"

MyComponent::MyComponent(){}

MyComponent::~MyComponent(){}

void MyComponent::Start()
{
	std::cout << "MyComponent1";
}
void MyComponent::FixedUpdate()
{
	std::cout << "MyComponent1";
}