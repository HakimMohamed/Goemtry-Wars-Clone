#include"Vector2.h"


Vector2::Vector2(float p_x, float p_y)
	:x(p_x)
	, y(p_y)
{
}

float Vector2::Distance(Vector2& v1, Vector2& v2)
{
	return (v2 - v1).getLength();
}

float Vector2::angle(Vector2& v1, Vector2& v2)
{
	auto v3 = v2 - v1;
	return atan2f(v3.y, v3.x) * radians;
}



Vector2 Vector2::Dir(Vector2& v1, Vector2& v2)
{
	return v2 - v1;
}


std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << " , " << other.y;
	return stream;
}


bool Vector2::operator == (const Vector2& other) const
{
	return (x == other.x && y == other.y);
}

bool Vector2::operator != (const Vector2& other) const
{
	return (x != other.x && y != other.y);
}



Vector2 Vector2::operator + (const Vector2& other)const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator - (const Vector2& other)const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator / (const float value)const
{
	return Vector2(x / value, y / value);
}

Vector2 Vector2::operator * (const float value)const
{
	return Vector2(x * value, y * value);
}




void Vector2::operator += (const Vector2& other)
{
	x += other.x;
	y += other.y;
}

void Vector2::operator -= (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
}

void Vector2::operator /= (const float value)
{
	x /= value;
	y /= value;
}

void Vector2::operator *= (const float value)
{
	x *= value;
	y *= value;
}





Vector2& Vector2::scale(float scaler)
{
	x *= scaler;
	y *= scaler;
	return *this;
}

Vector2& Vector2::normalized()
{
	x = x / this->getLength();
	y = y / this->getLength();
	return *this;
}



void Vector2::add(const Vector2& v)
{
	x += v.x;
	y += v.y;
}

void Vector2::normalize()
{
	x = x / this->getLength();
	y = y / this->getLength();
}





float Vector2::getLength() const
{
	return sqrtf((x * x) + (y * y));
}









