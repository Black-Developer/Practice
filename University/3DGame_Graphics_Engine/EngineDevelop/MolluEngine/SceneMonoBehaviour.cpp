#include "Time.h"
#include "SceneMonoBehaviour.h"
#include "SceneManager.h"
#include "GameObject.h"

void SceneMonoBehaviour::LoadScene()
{
	SceneManager::getInstance().SetScene(dynamic_cast<State*>(this));
}

void SceneMonoBehaviour::Execute()
{

	//Maybe i need Awake()

	for (unsigned int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects.at(i)->Start();
	}
	while (true)
	{
		if (Time::getInstance().IsFixedFrame())
		{
			for (unsigned int i = 0; i < gameObjects.size(); i++)
			{
				gameObjects.at(i)->FixedUpdate();
			}
		}
		for (unsigned int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects.at(i)->OnInput();
		}
		for (unsigned int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects.at(i)->Update();
		}
		for (unsigned int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects.at(i)->LateUpdate();
		}
		for (unsigned int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects.at(i)->Render();
		}
	}
}