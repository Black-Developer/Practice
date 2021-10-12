#include <iostream>
#include "FixedUpdate.h"
#include "Object.h"

FixedUpdate::FixedUpdate() {}
FixedUpdate::~FixedUpdate() {}

std::function <void()> FixedUpdate::FrameUpdate(void(*fp)())
{
	QueryPerformanceFrequency(&frequency);
	perFrame = frequency.QuadPart * const_Frame;
	QueryPerformanceCounter(&nowFrameCounter);
	timeDistance = nowFrameCounter.QuadPart - preFrameCounter.QuadPart;

	// Update Function
	if (timeDistance > perFrame)
	{
		if (fp != NULL)
		{
			fp();
		}
		preFrameCounter = nowFrameCounter;
	}
	return nullptr;
}