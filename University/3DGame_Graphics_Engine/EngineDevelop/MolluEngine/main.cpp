#include <iostream>
#include "MolluEngine.h"
#include "MolluEngineManager.h"
#include "BoxRenderer.h"

using namespace std;

int main(int argc, char** argv)
{

	IRenderer* Renderer = MolluEngineManager::getInstance().RenderingWithGL();


	MolluEngineManager::getInstance().Init(Renderer, argc, argv, 500,500);
	MolluEngineManager::getInstance().InitCamera(Renderer);

	GameObject* player = new GameObject();





	Scene* newScene = new Scene("newScene", 0);

	newScene->AddGameObject(player);

	SceneManager::getInstance().InitScene(newScene);
	SceneManager::getInstance().LoadScene(newScene);
	// Code Make


	player->transform.SetPosition(Vector3(0,0,0));
	player->transform.SetScale(Vector3(1, 1, 1));
	GL_BoxRenderer* boxRenderer = new GL_BoxRenderer(player);

	player->AddComponent(boxRenderer);
	MolluEngineManager::getInstance().Loop(Renderer);

	return 0;
}