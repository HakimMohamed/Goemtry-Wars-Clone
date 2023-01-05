#include"EntityManager.h"

EntityManager::EntityManager()
{
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto e = std::shared_ptr<Entity>(new Entity(tag,m_totalEntities++));
	//m_entities.push_back(e);
	//m_entitiesMap[tag].push_back(e);
	m_toAdd.push_back(e);

	return e;
}

EntityVec& EntityManager::getEntities()
{
	return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag)
{
	return m_entitiesMap[tag];
}




void EntityManager::removeDeadEntities(EntityVec& vec)
{
	
	
}

void EntityManager::update()
{

	for (auto& e : m_toAdd)
	{
		m_entities.push_back(e);
		m_entitiesMap[e->m_tag].push_back(e);
	}


	// map

	
	m_toAdd.clear();
}
