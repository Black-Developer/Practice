#ifndef __COMPONENTBOXCOLLISION_H__
#define __COMPONENTBOXCOLLISION_H__

#include "Component.h"

class ComponentBoxCollision : public Component
{
public:
	ComponentBoxCollision() {}
	~ComponentBoxCollision() override{}
	void Start();
	void Update();
	void FixedUpdate();
private:

};
#endif // !__COMPONENTBOXCOLLISION
