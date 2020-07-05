#pragma once

#include <cmath>
#include <stdlib.h>

class vec3 {
private : 
	union
	{
		struct {
			float _x, _y, _z;
		};
		struct {
			float r, g, b;
		};
	};

public : 
	inline vec3() : _x(0.f), _y (0.f), _z(0.f) {}
	inline vec3(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	inline vec3(const vec3& v) : _x(v._x), _y(v._y), _z(v._z) {}

	inline ~vec3()
	{

	}

	float getX() const { return _x; }
	float getY() const { return _y; }
	float getZ() const { return _z; }
	inline void setX(float x);
	inline void setY(float y);
	inline void setZ(float z);

	inline vec3& operator=(const vec3& v);
	inline vec3 operator*(const float t) const; 
	inline vec3 operator/(const float t) const;
	inline vec3 operator+(const vec3& rhs) const;
	inline vec3 operator+=(const vec3& rhs) const;
	inline vec3 operator-(const vec3& rhs) const;
	inline vec3 operator*(const vec3& rhs) const;
	inline float dot(const vec3& rhs) const;
	inline vec3& normalize();
	inline float norm();
	inline float getDistance(const vec3& other);
};

// equivalent a typedef vec3 color;
using color = vec3;

#include "vec3.inl"