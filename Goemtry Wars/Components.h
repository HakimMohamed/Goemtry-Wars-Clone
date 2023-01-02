#pragma once
#include"Vector2.h"
#include<SFML/Graphics.hpp>

struct CTransform
{
	Vector2 pos = { 0.0,0.0 };
	Vector2 vel = { 0.0,0.0 };

	CTransform(){}

	CTransform(const Vector2 & p,const Vector2 & v)
		:pos(p),vel(v)
	{
	}
};

struct CName
{
public:

	std::string name;

	CName(){}

	CName(const std::string &n) 
		:name(n)
	{}


};

struct CShape
{
	sf::CircleShape shape;

	CShape(){}

	CShape(const float & size,const sf::Color & color) 
	{
		shape.setRadius(size);
		shape.setFillColor(color);
	}

};

struct CBBOX
{

};