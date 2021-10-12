#ifndef __FIXEDUPDATE_H__
#define __FIXEDUPDATE_H__

#include <Windows.h>
#include <functional>

class FixedUpdate
{
public:
	std::function <void()> FrameUpdate(void(*fp)());
	FixedUpdate();
	~FixedUpdate();

private:
	LARGE_INTEGER	deltaTime;
	LARGE_INTEGER	frequency;
	LARGE_INTEGER	nowFrameCounter;
	LARGE_INTEGER	preFrameCounter;
	double			timeDistance;
	const float		const_Frame = 3.0f;
	int				perFrame;
};

#endif // !__FIXEDUPDATE_H__
