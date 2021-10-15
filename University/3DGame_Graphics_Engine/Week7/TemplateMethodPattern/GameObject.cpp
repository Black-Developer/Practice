#include "GameObject.h"
#include "Component.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::addComponent(Component *component)
{
	components.push_back(component);
}

void GameObject::loop()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->CallStart();
	}
	while (true)
	{
		for (int j = 0; j < components.size(); j++)
		{
			components.at(j)->Update();
		}
	}
}