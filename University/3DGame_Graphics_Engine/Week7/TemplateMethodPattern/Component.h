#ifndef __COMPONENT_H__
#define __COMPONENT_H__
#include <Windows.h>
#include <functional>

class Component
{
public:
	void CallStart();
	void Update();
	virtual void Start();
	virtual void FixedUpdate();
private:
	LARGE_INTEGER	deltaTime;
	LARGE_INTEGER	frequency;
	LARGE_INTEGER	nowFrameCounter;
	LARGE_INTEGER	preFrameCounter;
	double			timeDistance;
	const float		const_Frame = 1.0f;
	int				perFrame;
};

#endif // !__COMPONENT_H__
