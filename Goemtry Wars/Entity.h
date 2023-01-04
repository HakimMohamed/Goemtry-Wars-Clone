#pragma once
#include"Components.h"
class Entity
{
	const size_t m_id = 0;
	std::string m_tag = "Default";
	bool m_alive = true;
	friend class EntityManager;

public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape>		cShape;
	std::shared_ptr<CCollision>	cCollision;
	std::shared_ptr<CInput>		cInput;
	std::shared_ptr<CScore>		cScore;
	std::shared_ptr<CLifeSpan>	cLifeSpan;

	Entity();

	Entity(const std::string &tag,const size_t id);

	bool isActive() const;
	const std::string& tag() const;
	const size_t id() const;
	void destroy();
};

