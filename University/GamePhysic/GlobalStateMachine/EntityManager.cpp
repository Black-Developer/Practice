#include "EntityManager.h"
#include "GameEntity.h"
#include <cassert>

EntityManager* EntityManager::Instance()
{
	static EntityManager Instance;

	return &Instance;
}

GameEntity* EntityManager::GetEntityFromID(int id) const
{
	EntityMap::const_iterator ent = m_EntityMap.find(id);

	assert((ent != m_EntityMap.end()) && "<EntitiyManager::GetEntitiyFromID> : invalid ID");

	return ent->second;
}

void EntityManager::RegisterEntity(GameEntity* NewEntity)
{
	m_EntityMap.insert(std::make_pair(NewEntity->ID(), NewEntity));
}
void EntityManager::RemoveEntity(GameEntity* pEntity)
{
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}