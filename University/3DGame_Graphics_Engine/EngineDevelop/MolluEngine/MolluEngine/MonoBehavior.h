#ifndef __MONOBEHAVIOR_H__
#define __MONOBEHAVIOR_H__

#include "Component.h"

class MonoBehavior : public Component
{
public:
	MonoBehavior() {}
	virtual ~MonoBehavior() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}
};

#endif // !__MONOBEHAVIOUR_H__
