#ifndef __MONOBEHAVIOUR_H__
#define __MONOBEHAVIOUR_H__
#include "Component.h"

class MonoBehaviour : public Component
{
public:
	MonoBehaviour() {}
	virtual ~MonoBehaviour() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}
};

#endif // !__MONOBEHAVIOUR_H__
