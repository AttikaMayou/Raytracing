#pragma once

#include <cmath>

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
	vec3() : _x(0.f), _y (0.f), _z(0.f) {}
	vec3(float x, float y, float z);
	~vec3();

	float getX() { return _x; }
	float getY() { return _y; }
	float getZ() { return _z; }
	void setX(float x);
	void setY(float y);
	void setZ(float z);

	inline vec3 operator*(const float t) const;
	inline vec3 operator+(const vec3& rhs) const;
	inline vec3 operator-(const vec3& rhs) const;
	inline vec3 operator*(const vec3& rhs) const;
	inline float dot(const vec3& rhs) const;
	inline vec3& normalize();
};

// equivalent a typedef vec3 color;
using color = vec3;
