#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <vector>
#include "Transform.h"
#include "Component.h"
class GameObject
{
public:
	GameObject() {}
	virtual ~GameObject()
	{
		delete transform;
	}
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate() {}
	virtual void LateUpdate() {}
	virtual void OnInput() {}
	virtual void Render();
	void AddComponent(Component* component)
	{
		components.push_back(component);
	}
	Transform* transform;

	std::vector<Component*> components;
	std::vector<GameObject> child_GameObject;
private:
};

#endif //!__GAMEOBJECT_H__