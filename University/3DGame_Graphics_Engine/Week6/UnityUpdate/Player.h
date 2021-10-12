#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string.h>
#include "Object.h"

class Player : public Object
{
public:
	Player(std::string name) { m_Name = name; }
	~Player() {}
	virtual void Update() override;
	virtual void FixedUpdate() override;
};

#endif // !__PLAYER_H__
