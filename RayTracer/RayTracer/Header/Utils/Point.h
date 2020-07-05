#pragma once

#include <cmath>

class Point
{
private :
	struct { float x, y, z; };
public :
	Point();
	Point(float ax, float ay, float az);
	Point(const Point& p);
	~Point();

	Point& operator=(const Point& p);
	
	float getX() const { return x; };
	float getY() const { return y; };
	float getZ() const { return z; };
	void setX(float ax);
	void setY(float ay);
	void setZ(float az);

	Point operator*(const float t) const;
	Point operator/(const float t) const;
	Point operator+(const Point& p) const;
	Point operator-(const Point& p) const;
	Point operator*(const Point& p) const;
	Point operator+=(const Point& p) const;

	float norm();
	Point& normalized();
	float dot(const Point& p) const;
};