#ifndef __DELTATIME_H__
#define __DELTATIME_H__

#include <Windows.h>

class DeltaTime
{
public:
	DeltaTime();
	~DeltaTime();
	double getDeltaTime();
private:
	LARGE_INTEGER	deltaTime;
	LARGE_INTEGER	frequency;
	LARGE_INTEGER	nowFrameCounter;
	LARGE_INTEGER	preFrameCounter;
	double			timeDistance;
	const float		const_Frame = 3.0f;
	int				perFrame;
};

#endif // !__DELTATIME_H__
