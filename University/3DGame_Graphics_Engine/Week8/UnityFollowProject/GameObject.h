#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include <vector>
#include <string>
#include "Vector3.h"

class Component;

class GameObject
{
public:
	GameObject(std::string name): m_Name(name){}
	~GameObject() {}
	void addChild(GameObject*);
	void addComponent(Component*);

	std::string getName();

	void Start();
	void Update();
	void Render();

	void FixedUpdate();
	void OnInput();

	void setPosition(float, float, float);
	void setPosition(Vector3);
	void setScale(float, float, float);
	void setScale(Vector3);
private:
	std::string m_Name;
	std::vector<GameObject*> childObjects;
	std::vector<Component*> components;
	Vector3 position;
	Vector3 scale;
};

#endif // !__GAMEOBJECT_H__
