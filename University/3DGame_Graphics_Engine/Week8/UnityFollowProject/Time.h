#ifndef __TIME_H__
#define __TIME_H__
#include <Windows.h>
#include <functional>


class Time
{
public:
	static Time& instance()
	{
		static Time* instance = new Time();
		return *instance;
	}
	bool FrameUpdate(float);
private:
	LARGE_INTEGER	deltaTime;
	LARGE_INTEGER	frequency;
	LARGE_INTEGER	nowFrameCounter;
	LARGE_INTEGER	preFrameCounter;
	double			timeDistance;
	int				perFrame;
};

#endif // !__TIME_H__
