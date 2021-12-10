#include "Time.h"

bool Time::IsFixedFrame()
{
	QueryPerformanceFrequency(&frequency);
	frameRate = frequency.QuadPart / 60;
	QueryPerformanceCounter(&nowFrameCounter);
	timeDistance = nowFrameCounter.QuadPart - preFrameCounter.QuadPart;

	if (timeDistance > frameRate)
	{
		preFrameCounter = nowFrameCounter;
		return true;
	}
	return false;
}