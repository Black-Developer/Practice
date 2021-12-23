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

void MolluEngineManager::Init(IRenderer* renderer, int argc, char** argv, int windowWidth, int windowHeight)
{
	renderer->Init(argc, argv, windowWidth, windowHeight);
}

void MolluEngineManager::InitCamera(IRenderer* renderer)
{
	renderer->InitCamera();
}

IRenderer* MolluEngineManager::SetRenderer(ERenderer ERENDERER)
{
	switch (ERENDERER)
	{
	case isValid:
		break;
	case E_OPENGL:
		renderer = new GLRenderer();
		return renderer;
		break;
	case E_DIRECTX:
		renderer = new DXRenderer();
		return renderer;
		break;
	default:
		break;
	}
	return nullptr;
}