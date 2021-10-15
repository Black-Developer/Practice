#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <vector>

class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();
	void addComponent(Component *component);
	void loop();
private:
	std::vector<Component*> components;
};


#endif // !__GAMEOBJECT_H__
