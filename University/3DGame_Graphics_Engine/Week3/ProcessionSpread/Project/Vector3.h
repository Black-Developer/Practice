#ifndef __VECTOR3_H__

class Vector3
{
public:
	Vector3();
	Vector3(int, int, int);
	float x_;
	float y_;
	float z_;

	friend Vector3 operator+=(const Vector3& vector1, const Vector3& vector2)
	{
		Vector3 addVector = { 0,0,0 };
		addVector.x_ = vector1.x_ + vector2.x_;
		addVector.y_ = vector1.y_ + vector2.y_;
		addVector.z_ = vector1.z_ + vector2.z_;

		return (addVector);
	}
};
#endif // !__VECTOR3_H__
