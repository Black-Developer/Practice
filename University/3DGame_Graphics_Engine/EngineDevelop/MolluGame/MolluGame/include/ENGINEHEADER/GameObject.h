#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <vector>
#include "Transform.h"

class Component;

class GameObject
{
public:
	GameObject() {}
	virtual ~GameObject() {}
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate() {}
	virtual void LateUpdate() {}
	virtual void OnInput() {}
	virtual void Render();
	Transform transform;
	
private:
	std::vector<Component>* components;
	std::vector<GameObject> child_GameObject;
};

#endif //!__GAMEOBJECT_H__