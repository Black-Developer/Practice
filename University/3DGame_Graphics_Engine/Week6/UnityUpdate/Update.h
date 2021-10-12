#ifndef __UPDATE_H__
#define __UPDATE_H__

#include <functional>
#include <Windows.h>

class Update
{
public:
	std::function <void()> FrameUpdate(void(*fp)());
	Update();
	~Update();

private:
	LARGE_INTEGER	deltaTime;
	LARGE_INTEGER	frequency;
	LARGE_INTEGER	nowFrameCounter;
	LARGE_INTEGER	preFrameCounter;
	double			timeDistance;
	const float		const_Frame = 1.0f;
	int				perFrame;
};

#endif // !__UPDATE_H__
