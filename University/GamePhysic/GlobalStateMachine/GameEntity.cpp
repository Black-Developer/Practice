#include "GameEntity.h"

int GameEntity::m_iNextValidID = 0;


void GameEntity::SetID(int val)
{
	m_ID = val;
	m_iNextValidID = m_ID + 1;
}