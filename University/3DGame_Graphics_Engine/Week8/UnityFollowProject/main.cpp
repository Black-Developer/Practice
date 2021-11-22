#include <iostream>
#include "Scene.h"
#include "Component.h"
#include "GameObject.h"
#include "ComponentBoxRenderer.h"
#include "ComponentTriangleRenderer.h"
#include "ComponentBoxCollision.h"


using namespace std;


int main()
{
	Component* triangle = new ComponentTriangleRenderer();
	Component* collision = new ComponentBoxCollision();
	GameObject* body = new GameObject("body");
	body->setPosition(0.0f, 0.0f, 0.0f);
	body->addComponent(triangle);
	body->addComponent(collision);

	Component* box = new ComponentBoxRenderer();
	GameObject* turret = new GameObject("turret");
	body->addChild(turret);
	turret->setPosition(0.0f, 0.0f, 2.0f);
	turret->setScale(0.5f, 0.5f, 2.0f);
	turret->addComponent(box);

	Scene* scene = new Scene("scene name");
	scene->addGameObject(body);
	scene->addGameObject(turret);


	scene->Loop();

	return 0;
}