#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include <string>
#include <map>
#include "StateMachine.h"

class Scene;

class SceneManager
{
private:
	SceneManager()
	{
		m_pStateMachine = new StateMachine;
		m_pStateMachine->SetCurrentState(nullptr);
		m_pStateMachine->SetGlobalState(nullptr);
	}
	SceneManager(const SceneManager& reference) {}
	SceneManager& operator=(const SceneManager& reference) {}
	~SceneManager() { delete m_pStateMachine; }


	std::map<Scene*, int> scene_Array;
	
	StateMachine *m_pStateMachine;
public:
	static SceneManager& getInstance()
	{
		static SceneManager instance;
		return instance;
	}
	void InitScene(State*);
	void AddScene(Scene* scene);
	void SetScene(State*);
	void PlayScene();
};

#endif // !__SCENEMANAGER_H__
