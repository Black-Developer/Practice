#ifndef __SCENEMONOBEHAIOUR_H__
#define __SCENEMONOBEHAIOUR_H__
#include <vector>
#include <string>
#include "State.h"

class GameObject;

class SceneMonoBehavior : public State
{
public:
	SceneMonoBehavior() {}
	virtual ~SceneMonoBehavior() = 0 {}

	std::vector<GameObject*> gameObjects;
	int index;
	std::string name;
	void LoadScene();
private:
	void Enter();
	void Execute();
	void Exit() {}
};

#endif // !__SCENESTATE_H__
