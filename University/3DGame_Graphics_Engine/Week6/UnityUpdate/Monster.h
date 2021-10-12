#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <string.h>
#include "Object.h"

class Monster : public Object
{
public:
	Monster(std::string name) { m_Name = name; }
	~Monster() {}
	virtual void Update() override;
	virtual void FixedUpdate() override;
};

#endif // !__MONSTER_H__