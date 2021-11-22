#include "SceneManager.h"
#include "Scene.h"

void SceneManager::InitScene(State* scene)
{
	m_pStateMachine->SetCurrentState(scene);
}

void SceneManager::SetScene(State* scene)
{
	m_pStateMachine->ChangeState(scene);
}

void  SceneManager::AddScene(Scene* scene)
{
	scene_Array.insert({ scene, scene->GetIndex() });
}

void SceneManager::PlayScene()
{
	m_pStateMachine->Update();
}
