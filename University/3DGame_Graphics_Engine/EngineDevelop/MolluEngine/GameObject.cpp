#include "GameObject.h"
#include "Component.h"
#include <iostream>

void GameObject::Start()
{
	if (!components.empty())
	{
		for (int i = 0; i < components.size(); i++)
		{
			components.at(i)->Start();
		}
	}
}
void GameObject::Update()
{
	if (!components.empty())
	{
		for (int i = 0; i < components.size(); i++)
		{
			components.at(i)->Update();
		}
	}
}

void GameObject::Render()
{
	if (!components.empty())
	{
		for (int i = 0; i < components.size(); i++)
		{
			components.at(i)->Render();
		}
	}
}