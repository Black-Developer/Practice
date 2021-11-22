#include "GameObject.h"
#include "Component.h"
#include <iostream>


void GameObject::addChild(GameObject* gameObject)
{
	std::cout << m_Name << " To Add child GameObject : " << gameObject->getName() << std::endl;
	childObjects.push_back(gameObject);
}
void GameObject::addComponent(Component* component)
{
	components.push_back(component);
}

void GameObject::setPosition(Vector3 transform)
{
	position += transform;
	std::cout << m_Name
		<< " set Position :"
		<< position.x << ", "
		<< position.y << ", "
		<< position.z << std::endl;
	if (!childObjects.empty())
	{
		for (std::vector<GameObject*>::iterator iter = childObjects.begin(); iter != childObjects.end(); iter++)
		{
			(*iter)->setPosition(transform);
		}
	}
}
void GameObject::setPosition(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
	std::cout << m_Name
		<< " set Position :"
		<< position.x << ", "
		<< position.y << ", "
		<< position.z << std::endl;

	if (!childObjects.empty())
	{
		for (std::vector<GameObject*>::iterator iter = childObjects.begin(); iter != childObjects.end(); iter++)
		{
			(*iter)->setPosition(x, y, z);
		}
	}
}

void GameObject::setScale(float x, float y, float z)
{
	scale.x += x;
	scale.y += y;
	scale.z += z;
	std::cout << m_Name
		<< " set Scale :"
		<< scale.x << ", "
		<< scale.y << ", "
		<< scale.z << std::endl;
}
void GameObject::setScale(Vector3 scale)
{
	this->scale += scale;
	std::cout << m_Name
		<< " set Scale :"
		<< scale.x << ", "
		<< scale.y << ", "
		<< scale.z << std::endl;
}


void GameObject::Start()
{
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		components.at(i)->Start();
	}
}
void GameObject::Update()
{
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		components.at(i)->Update();
	}
}
void GameObject::FixedUpdate()
{
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		components.at(i)->FixedUpdate();
	}
}
void GameObject::Render()
{
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		components.at(i)->Render();
	}
}
void GameObject::OnInput()
{
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		components.at(i)->OnInput();
	}
}

std::string GameObject::getName()
{
	return m_Name;
}