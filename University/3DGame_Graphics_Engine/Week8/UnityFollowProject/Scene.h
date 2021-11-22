#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>
#include <vector>

class GameObject;

class Scene
{
public:
	Scene(std::string name) :m_Name(name){}
	~Scene() {}
	void Loop();
	void addGameObject(GameObject*);
private:
	std::string m_Name;
	std::vector<GameObject*> gameObjects;
};

#endif // !__SCENE_H__
