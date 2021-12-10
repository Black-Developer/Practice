#include <iostream>
#include "../../MolluEngine/MolluEngine/MolluEngine.h"
#include "../../MolluEngine/MolluEngine/MolluEngineManager.h"

#include "../../MolluEngine//MolluEngine/BoxRender.h"

using namespace std;



int main(int argc, char** argv)
{
	IRenderer* renderer =  MolluEngineManager::getInstance().SetRenderer(ERenderer::E_DIRECTX);


	MolluEngineManager::getInstance().Init(renderer, argc, argv, 500, 500);
	MolluEngineManager::getInstance().InitCamera(renderer);

	GameObject* player = new GameObject();


	Scene* newScene = new Scene("newScene", 0);

	newScene->AddGameObject(player);

	SceneManager::getInstance().InitScene(newScene);
	SceneManager::getInstance().LoadScene(newScene);
	// Code Make


	player->transform->SetPosition(Vector3(0, 0, 0));
	player->transform->SetScale(Vector3(1, 1, 1));
	BoxRender* boxRender = new BoxRender(player);

	player->AddComponent(boxRender);

	MolluEngineManager::getInstance().Loop(renderer);

	return 0;
}