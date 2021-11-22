#include "MolluEngineManager.h"
#include "SceneManager.h"
#include "OpenGLRenderer.h"

void MolluEngineManager::Loop(IRenderer* render)
{
	// 씬을 설정하고 실행
	//SceneManager::getInstance().SetScene();

	render->Loop();

	//while (true)
	//{
	//	SceneManager::getInstance().PlayScene();
	//
	//}

}

void MolluEngineManager::Init(IRenderer* render, int argc, char** argv)
{
	render->Init(argc, argv);
}

void MolluEngineManager::InitCamera(IRenderer* render)
{
	render->InitCamera();
}