#pragma once

#include<math.h>
#include<iostream>

#define radians 57.29578f;

class Vector2
{
private:

public:
	float x = 0;
	float y = 0;

	Vector2() {}
	Vector2(float p_x, float p_y);

	static float Distance(Vector2& v1, Vector2& v2);
	static float angle(Vector2& v1, Vector2& v2);

	static Vector2 Dir(Vector2& v1, Vector2& v2);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2& other);

	bool operator ==(const Vector2& other) const;
	bool operator !=(const Vector2& other)const;

	Vector2  operator + (const Vector2& other)const;
	Vector2  operator - (const Vector2& other)const;
	Vector2  operator / (const float value)const;
	Vector2  operator * (const float value)const;

	void	operator +=(const Vector2& other);
	void	operator -=(const Vector2& other);
	void	operator *=(const float value);
	void	operator /=(const float value);

	Vector2& scale(float scaler);
	Vector2& normalized();

	void add(const Vector2& other);
	void normalize();

	float getLength()const;

	//s

};


