#include "SceneManager.h"
#include "Scene.h"

void SceneManager::InitScene(State* scene)
{
	m_pStateMachine->SetCurrentState(scene);
}
void  SceneManager::AddScene(Scene* scene)
{
	scene_Array.insert(std::make_pair(scene, scene->GetIndex()));
}
void SceneManager::LoadScene(Scene* scene)
{
	m_pStateMachine->ChangeState(scene);
}
void SceneManager::LoadScene(State* state)
{
	m_pStateMachine->ChangeState(state);
}
void SceneManager::PlayScene()
{
	m_pStateMachine->Update();
}