#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component
{
public:
	Component() {}
	virtual ~Component() = 0 {}
	virtual void Start() {}
	virtual void Update();
	virtual void Render(){}
};

#endif // !__COMPONENT_H__