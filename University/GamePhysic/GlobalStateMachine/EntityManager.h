#pragma once

#include <map>


#define EntityMgr EntityManager::Instance()


class GameEntity;

class EntityManager
{
private:
	typedef std::map<int, GameEntity*>EntityMap;

	EntityMap m_EntityMap;
	EntityManager() {}

public:
	static EntityManager* Instance();

	GameEntity* GetEntityFromID(int id) const;
	void RegisterEntity(GameEntity* NewEntity);
	void RemoveEntity(GameEntity* pEntity);


};
