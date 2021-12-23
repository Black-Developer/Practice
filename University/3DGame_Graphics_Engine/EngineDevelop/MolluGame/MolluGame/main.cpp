#include <iostream> 

#include "../../MolluEngine/MolluEngine/MolluEngine.h"
#include "../../MolluEngine/MolluEngine/MolluEngineManager.h"
#include "../../MolluEngine//MolluEngine/BoxRender.h"
#include "../../MolluEngine/MolluEngine/TextureRender.h"

int main(int argc, char** argv)
{
	IRenderer* renderer =  MolluEngineManager::getInstance().SetRenderer(ERenderer::E_OPENGL);
	
	
	MolluEngineManager::getInstance().Init(renderer, argc, argv, 500, 500);
	MolluEngineManager::getInstance().InitCamera(renderer);
	
	GameObject* player = new GameObject();
	
	GameObject* mollu = new GameObject();
	
	Scene* newScene = new Scene("newScene", 0);
	
	newScene->AddGameObject(player);
	newScene->AddGameObject(mollu);



	SceneManager::getInstance().InitScene(newScene);
	SceneManager::getInstance().LoadScene(newScene);
	// Code Make
	
	
	player->transform->SetPosition(Vector3(0, 0, 0));
	player->transform->SetScale(Vector3(0.5, 0.5, 0.5));
	BoxRender* boxRender = new BoxRender(player);
	player->AddComponent(boxRender);
	
	mollu->transform->SetPosition(Vector3(0, 0, 0));
	mollu->transform->SetScale(Vector3(1, 1, 1));
	TextureRender* molluTexture = new TextureRender("Mollu.bmp", mollu, argv);
	mollu->AddComponent(molluTexture);

	MolluEngineManager::getInstance().Loop(renderer);
	
	delete renderer;
	delete player;
	delete newScene;
	delete boxRender;
	
	return 0;
}