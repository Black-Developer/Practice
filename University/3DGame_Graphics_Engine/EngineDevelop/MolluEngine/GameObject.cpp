#include "GameObject.h"
#include "Component.h"
#include <iostream>

void GameObject::Start()
{
	if (components != NULL)
	{
		for (int i = 0; i < components->size(); i++)
		{
			components->at(i).Start();
		}
	}
}
void GameObject::Update()
{
	if (components != NULL)
	{
		for (int i = 0; i < components->size(); i++)
		{
			std::cout << "GameObject Update" << std::endl;
			components->at(i).Update();
		}
	}
}

void GameObject::Render()
{
	if (components != NULL)
	{
		for (int i = 0; i < components->size(); i++)
		{
			components->at(i).Render();
		}
	}
}