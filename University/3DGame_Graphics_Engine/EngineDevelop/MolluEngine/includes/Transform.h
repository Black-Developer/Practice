#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Component.h"
#include "Vector.h"

class Transform : public Component
{
public:
	Transform() : position(0, 0, 0) {}
	~Transform() {}
	void SetPosition(float, float, float);
	void SetPosition(Vector3&);
	void SetPosition(Vector3);
	void SetScale(float, float, float);
	void SetScale(Vector3&);
	void SetScale(Vector3);


	Vector3 position;
	Vector3 scale;
	Vector3 GetPosition() const;
};

#endif // !__TRANSFORM_H__
