#include <iostream>
#include "MolluEngine.h"
#include "MolluEngineManager.h"
#include "ENGINEHEADER/OpenGLRenderer.h"


using namespace std;


int main(int argc, char** argv)
{
	cout << "Mol?lu" << endl;

	IRenderer* Renderer = new GLRenderer();
	MolluEngineManager::getInstance();

	MolluEngineManager::getInstance().Init(Renderer, argc, argv);
	MolluEngineManager::getInstance().InitCamera(Renderer);

	GameObject* player = new GameObject();

	Scene* newScene = new Scene("newScene",0);
	

	newScene->AddGameObject(player);
	SceneManager::getInstance().InitScene(newScene);
	SceneManager::getInstance().SetScene(newScene);

	MolluEngineManager::getInstance().Loop(Renderer);

	return 0;
}