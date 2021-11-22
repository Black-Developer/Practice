#ifndef __VECTOR3_H__
#define __VECTOR3_H__

class Vector3
{
public:
	Vector3() :x(0),y(0),z(0) {}
	~Vector3() {}
	float x;
	float y;
	float z;
	void operator+=(const Vector3& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
	}
	void operator-=(const Vector3& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
	}
	Vector3 operator+(const Vector3& vector)
	{
		Vector3 addVector;
		addVector.x = vector.x + x;
		addVector.y = vector.y + y;
		addVector.z = vector.z + z;
		return addVector;
	}
};


#endif // !__VECTOR3_H__
