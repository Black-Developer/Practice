#include "Transform.h"

void Transform::SetPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}
void Transform::SetPosition(Vector3 newPosition)
{
	position = newPosition;
}

void Transform::SetPosition(Vector3& newPosition)
{
	position = newPosition;
}
void Transform::SetScale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
	scale.z = z;
}
void Transform::SetScale(Vector3 newScale)
{
	scale = newScale;
}
void Transform::SetScale(Vector3& newScale)
{
	scale = newScale;
}

Vector3 Transform::GetPosition() const
{
	return position;
}