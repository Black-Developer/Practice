#include <iostream>
#include "Scene.h"
#include "GameObject.h"
#include "Time.h"

void Scene::Loop()
{
	for (int i = 0; i < gameObjects.size(); ++i)
	{
		gameObjects.at(i)->Start();
	}
	while (true)
	{
		if (Time::instance().FrameUpdate(1.0f))
		{
			for (int i = 0; i < gameObjects.size(); ++i)
			{
				gameObjects.at(i)->FixedUpdate();
			}
		}
		for (int i = 0; i < gameObjects.size(); ++i)
		{
			gameObjects.at(i)->OnInput();
		}
		for (int i = 0; i < gameObjects.size(); ++i)
		{
			gameObjects.at(i)->Update();
		}
		for (int i = 0; i < gameObjects.size(); ++i)
		{
			gameObjects.at(i)->Render();
		}
	}
}

void Scene::addGameObject(GameObject* gameObject)
{
	std::cout << "Scene ADD OBJ : " << gameObject->getName() << std::endl;
	gameObjects.push_back(gameObject);
}