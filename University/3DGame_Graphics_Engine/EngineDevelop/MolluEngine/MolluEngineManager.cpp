#include "MolluEngineManager.h"
#include "SceneManager.h"
#include "OpenGLRenderer.h"
#include "DXRenderer.h"
void MolluEngineManager::Loop(IRenderer* render)
{
	while (true)
	{
	SceneManager::getInstance().PlayScene();
	render->Loop();
	}
}

void MolluEngineManager::Init(IRenderer* render, int argc, char** argv, int windowWidth, int windowHeight)
{
	render->Init(argc, argv, windowWidth, windowHeight);
}

void MolluEngineManager::InitCamera(IRenderer* render)
{
	render->InitCamera();
}

IRenderer* MolluEngineManager::RenderingWithDX() { return new DXRenderer(); }
IRenderer* MolluEngineManager::RenderingWithGL() { return new GLRenderer(); }