#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "monoBehaviour.h"

class Component : public monoBehaviour
{
public:
	virtual void OnInput() {}
	virtual void Render() {}
	virtual void FixedUpdate() {}
};

#endif // !__COMPONENT_H__