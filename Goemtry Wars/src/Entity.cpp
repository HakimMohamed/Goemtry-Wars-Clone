#include "Entity.h"

bool Entity::isActive() const
{
    return _active;
}

const std::string& Entity::tag() const
{
    return _tag;
}

const size_t Entity::id() const
{
    return _id;
}
