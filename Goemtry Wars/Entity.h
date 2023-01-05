#pragma once
#include"Components.h"
#include<memory>

class Entity
{
	friend class EntityManager;

	const size_t m_id = 0;
	std::string m_tag = "default";
	bool m_alive = true;
	Entity(const std::string& tag, const size_t id);

public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape>		cShape;
	std::shared_ptr<CCollision>	cCollision;
	std::shared_ptr<CInput>		cInput;
	std::shared_ptr<CScore>		cScore;
	std::shared_ptr<CLifeSpan>	cLifeSpan;

	Entity();


	bool isActive() const;
	const std::string& tag() const;
	const size_t id() const;
	void destroy();
};

