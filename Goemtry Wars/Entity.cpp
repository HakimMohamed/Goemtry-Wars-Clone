#include "Entity.h"
#include<memory>

Entity::Entity()
{
}

Entity::Entity(const std::string& tag, const size_t id)
	:m_tag(tag),m_id(id)
{
}

bool Entity::isActive() const
{
	return m_alive;
}

const std::string& Entity::tag() const
{
	return m_tag;
}



const size_t Entity::id() const
{
	return m_id;
}

void Entity::destroy()
{
	m_alive = false;
}


