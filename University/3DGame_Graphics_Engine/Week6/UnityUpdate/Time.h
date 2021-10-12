#ifndef __TIME_H__
#define __TIME_H__

#include "Update.h"
#include "FixedUpdate.h"
#include "DeltaTime.h"

class Time
{
public:
	static Time& instance()
	{
		static Time* instance = new Time();
		return *instance;
	}
	Update*		getUpdate() { return &update; }
	FixedUpdate* getFixedUpdate() { return &fixedUpdate; }
	float getDeltaTime() { return deltaTime.getDeltaTime(); }
private:
	Update		update;
	FixedUpdate fixedUpdate;
	DeltaTime deltaTime;
};

#endif // !_TIME_H__
