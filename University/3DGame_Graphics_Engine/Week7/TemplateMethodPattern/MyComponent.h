#ifndef __MYCOMPONENT_H__
#define __MYCOMPONENT_H__

#include "Component.h"

class MyComponent : public Component
{
public:
	MyComponent();
	~MyComponent();
	virtual void Start();
	virtual void FixedUpdate();
};



#endif // !__MYCOMPONENT_H__
