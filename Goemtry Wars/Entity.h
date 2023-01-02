#pragma once
#include"Components.h"

class Entity
{
public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CName>		cName;
	std::shared_ptr<CShape>		cShape;
	std::shared_ptr<CBBOX>		cBbox;

	Entity();


};

