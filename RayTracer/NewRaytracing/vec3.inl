#include "vec3.h"

inline void vec3::setX(float x)
{
	_x = x;
}

inline void vec3::setY(float y)
{
	_y = y;
}

inline void vec3::setZ(float z)
{
	_z = z;
}

inline vec3& vec3::operator=(const vec3& v)
{
	_x = v._x;
	_y = v._y;
	_z = v._z;
	return *this;
}

inline vec3 vec3::operator*(const float t) const
{
	return { _x * t, _y * t, _z * t };
}

inline vec3 vec3::operator/(const float t) const
{
	return{ _x / t, _y / t, _z / t };
}

inline vec3 vec3::operator+(const vec3& rhs) const
{
	return{ _x + rhs._x, _y + rhs._y, _z + rhs._z };
}

inline vec3 vec3::operator+=(const vec3& rhs) const
{
	return *this + rhs;
}

inline vec3 vec3::operator-(const vec3& rhs) const
{
	return{ _x - rhs._x, _y - rhs._y, _z - rhs._z };
}

inline vec3 vec3::operator*(const vec3& rhs) const
{
	return{ _x * rhs._x, _y * rhs._y, _z * rhs._z };
}


inline float vec3::operator[](const int index) const {
	if (index == 0) {
		return _x;
	}
	else if (index == 1) {
		return _y;

	}
	else if (index == 2) {
		return _z;
	}
}

inline float vec3::dot(const vec3& rhs) const
{
	return _x * rhs._x + _y * rhs._y + _z * rhs._z;
}

inline float vec3::squareLenght() const {
	return _x * _x + _y + _y + _z + _z;
}

inline vec3& vec3::normalize()
{
	float inv_length = 1.f / sqrtf(_x * _x + _y * _y + _z * _z);
	_x *= inv_length;
	_y *= inv_length;
	_z *= inv_length;
	return *this;
}

inline float vec3::norm() {
	return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}

inline float vec3::getDistance(const vec3& other) {
	return sqrt(pow(other.getX() - getX(), 2) + pow(other.getY() - getY(), 2) + pow(other.getZ() - getZ(), 2));
}

inline float dot(const vec3& v1, const vec3& v2) {
	return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

inline vec3 unitVector(vec3 v) {
	return v / v.norm();
}

inline vec3 cross(const vec3& v1, const vec3& v2) {
	return vec3(
		(v1.getY() * v2.getZ() - v1.getZ() * v2.getY()),
		(-(v1.getX() * v2.getZ() - v1.getZ() * v2.getX())),
		(v1.getX() * v2.getY() - v1.getY() * v2.getX())
	);
}