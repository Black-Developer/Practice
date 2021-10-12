#include "DeltaTime.h"
#include <Windows.h>
#include <iostream>

DeltaTime::DeltaTime(){}
DeltaTime::~DeltaTime(){}

double DeltaTime::getDeltaTime()
{
	QueryPerformanceFrequency(&frequency);
	perFrame = frequency.QuadPart * const_Frame;
	QueryPerformanceCounter(&nowFrameCounter);
	timeDistance = nowFrameCounter.QuadPart - preFrameCounter.QuadPart;

	// Update Function
	if (timeDistance > perFrame)
	{
		preFrameCounter = nowFrameCounter;
	}
	return (timeDistance / 10000000);
}