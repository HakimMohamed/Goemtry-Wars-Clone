#pragma once

#include<iostream>
#include<vector>
#include"Entity.h"
#include<map>

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string,EntityVec> EntityMap;

class EntityManager
{
	EntityVec m_entities;
	EntityMap m_entitiesMap;
	size_t	  m_totalEntities = 0;
	EntityVec m_toAdd;

public:
	EntityManager();

	std::shared_ptr<Entity> addEntity(const std::string& tag);

	EntityVec& getEntities();
	EntityVec& getEntities(const std::string& tag);

	void removeDeadEntities(EntityVec& vec);
	void update();
	
};