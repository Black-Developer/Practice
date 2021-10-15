#ifndef __MYCOMPONENT2_H__
#define __MYCOMPONENT2_H__

#include "Component.h"

class MyComponent2 : public Component
{
public:
	MyComponent2();
	~MyComponent2();
	virtual void Start();
	virtual void FixedUpdate();
};


#endif // !__MYCOMPONENT2_H__
