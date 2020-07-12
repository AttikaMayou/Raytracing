#include "../../Header/Utils/Point.h"

Point::Point()
	: x(0.f), y(0.f), z(0.f)
{
}

Point::Point(float ax, float ay, float az)
	: x(ax), y(ay), z(az)
{
}

Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}

Point::~Point()
{
}

Point& Point::operator=(const Point& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
}

void Point::setX(float ax)
{
	x = ax;
}

void Point::setY(float ay)
{
	y = ay;
}

void Point::setZ(float az)
{
	z = az;
}

Point Point::operator*(const float t) const
{
	return { x * t, y * t, z * t };
}

Point Point::operator/(const float t) const
{
	return{ x / t, y / t, z / t };
}

Point Point::operator+(const Point& p) const
{
	return{ x + p.x, y + p.y, z + p.z };
}

Point Point::operator-(const Point& p) const
{
	return{ x - p.x, y - p.y, z - p.z };
}

Point Point::operator*(const Point& p) const
{
	return { x * p.x, y * p.y, z * p.z };
}

Point Point::operator+=(const Point& p) const
{
	return *this + p;
}

float Point::norm()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Point& Point::normalized()
{
	float invLength = 1.f / sqrtf(x * x + y * y + z * z);
	x *= invLength;
	y *= invLength;
	z *= invLength;
	return *this;
}

float Point::dot(const Point& p) const
{
	return x * p.x + y * p.y + z * p.z;
}
