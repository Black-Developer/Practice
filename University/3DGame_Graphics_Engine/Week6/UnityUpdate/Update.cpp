#include "Update.h"

#include <iostream>

Update::Update() {}
Update::~Update() {}

std::function <void()> Update::FrameUpdate(void(*fp)())
{
	QueryPerformanceFrequency(&frequency);
	perFrame = frequency.QuadPart / const_Frame;
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