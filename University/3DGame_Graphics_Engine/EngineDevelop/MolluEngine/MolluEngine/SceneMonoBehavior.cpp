#include "Time.h"
#include "SceneMonoBehavior.h"
#include "SceneManager.h"
#include "GameObject.h"

void SceneMonoBehavior::LoadScene()
{
	SceneManager::getInstance().LoadScene(dynamic_cast<State*>(this));
}

void SceneMonoBehavior::Enter()
{
	for (unsigned int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects.at(i)->Start();
	}
}

void SceneMonoBehavior::Execute()
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