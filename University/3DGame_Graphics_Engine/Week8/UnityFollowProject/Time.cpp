#include "Time.h"
#include "GameObject.h"
bool Time::FrameUpdate(float frame)
{
	QueryPerformanceFrequency(&frequency);
	perFrame = frequency.QuadPart / frame;
	QueryPerformanceCounter(&nowFrameCounter);
	timeDistance = nowFrameCounter.QuadPart - preFrameCounter.QuadPart;

	// Update Function
	if (timeDistance > perFrame)
	{
		preFrameCounter = nowFrameCounter;
		return true;
	}
	return false;
}