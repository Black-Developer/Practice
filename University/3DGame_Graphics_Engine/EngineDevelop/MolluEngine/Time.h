#ifndef __TIME_H__
#define __TIME_H__
#include <Windows.h>

class Time
{
private:
	Time() {}
	Time(const Time& ref) {}
	Time& operator=(const Time& ref) {}
	~Time() {}
	LARGE_INTEGER deltaTime;
	LARGE_INTEGER frequency;
	LARGE_INTEGER nowFrameCounter;
	LARGE_INTEGER preFrameCounter;
	double timeDistance;
	int frameRate;
public:
	static Time& getInstance()
	{
		static Time instance;
		return instance;
	}
	bool IsFixedFrame();
};

#endif // !
