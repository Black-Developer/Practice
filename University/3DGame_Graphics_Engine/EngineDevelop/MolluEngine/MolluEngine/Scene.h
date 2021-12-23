#ifndef __SCENE_H__
#define __SCENE_H__

#include <vector>
#include <string>
#include "SceneMonoBehavior.h"

class GameObject;


class Scene : public SceneMonoBehavior
{
private:
	Scene() {}
public:
	Scene(std::string _name, int _index);
	virtual ~Scene() {};
	void AddGameObject(GameObject*);
	int GetIndex();
	std::string GetName();
};

#endif // !__Scene_H__
