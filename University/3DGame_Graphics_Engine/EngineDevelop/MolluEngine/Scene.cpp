#include "Scene.h"
#include "GameObject.h"
#include "Time.h"
#include "SceneManager.h"

Scene::Scene(string _name, int _index)
{
	name = _name;
	index = _index;
	SceneManager::getInstance().AddScene(this);
}

void Scene::AddGameObject(GameObject *gameObject)
{
	gameObjects.push_back(gameObject);
}

string Scene::GetName()
{
	return name;
}

int Scene::GetIndex()
{
	return index;
}