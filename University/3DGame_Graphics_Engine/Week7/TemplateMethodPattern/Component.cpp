#include <iostream>
#include "Component.h"
#include "MyComponent.h"
#include "MyComponent2.h"

void Component::CallStart()
{
	Start();
	std::cout << "\tSTART\n";
}
void Component::Start()
{
	std::cout << "Cant' Start\n";
}
void Component::FixedUpdate()
{
	std::cout << "NULL Component\n";
}

void Component::Update()
{
	QueryPerformanceFrequency(&frequency);
	perFrame = frequency.QuadPart / const_Frame;
	QueryPerformanceCounter(&nowFrameCounter);
	timeDistance = nowFrameCounter.QuadPart - preFrameCounter.QuadPart;

	// Update Function
	if (timeDistance > perFrame)
	{
		FixedUpdate();
		std::cout << "\tFixedUpdate Call\n";
		preFrameCounter = nowFrameCounter;
	}
	return;
}