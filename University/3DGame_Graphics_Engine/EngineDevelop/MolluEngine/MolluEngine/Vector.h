#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector3
{
public:
	Vector3() : x(0), y(0), z(0) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	float x;
	float y;
	float z;
};

class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}
	float x;
	float y;
};

#endif __VECTOR_H__ // !__VECTOR_H__