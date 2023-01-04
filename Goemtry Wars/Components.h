#pragma once
#include"Vector2.h"
#include<SFML/Graphics.hpp>

struct CTransform
{
	Vector2 pos = { 0.0,0.0 };
	Vector2 vel = { 0.0,0.0 };
	float  angle = 0;

	CTransform(){}

	CTransform(const Vector2 & p,const Vector2 & v)
		:pos(p),vel(v)
	{
	}
};

struct CShape
{
	sf::CircleShape shape;



	CShape(float radius, int points, const sf::Color& fill, const sf::Color &outline, float thickness)
		:shape(radius,points)
	{
		shape.setFillColor(fill);
		shape.setOutlineColor(outline);
		shape.setOutlineThickness(thickness);
		shape.setOrigin(radius, radius);
	}

};





struct CBBOX
{

};

struct CCollision
{

	float radius = 0;
	 CCollision(float r)
		 :radius(r)
	 {}

};

struct CScore
{
public:
	int score = 0;
	CScore (int s)
		: score(s) {}
};

struct CInput
{
	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;
	bool shoot = false; 

	CInput() {};
};

struct CLifeSpan
{
public:

	int remaining = 0;
	int total	  = 0;

	CLifeSpan(int total)
		:remaining(total),total(total)
	{}


};

