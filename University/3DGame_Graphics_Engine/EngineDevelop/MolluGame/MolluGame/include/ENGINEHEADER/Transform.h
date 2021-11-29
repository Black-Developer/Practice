#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Vector.h"


class Transform
{
public:
	Transform() : position(0,0,0){}
	~Transform() {}
	void SetPosition(float, float, float);
	void SetPosition(Vector3);
	Vector3 GetPosition() const;
private:
	Vector3 position;
};

#endif // !__TRANSFORM_H__
