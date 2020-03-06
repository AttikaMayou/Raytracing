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

inline vec3 vec3::operator*(const float t) const
{
	return { _x * t, _y * t, _z * t };
}

inline vec3 vec3::operator+(const vec3& rhs) const
{
	return{ _x + rhs._x, _y + rhs._y, _z + rhs._z };
}

inline vec3 vec3::operator-(const vec3& rhs) const
{
	return{ _x - rhs._x, _y - rhs._y, _z - rhs._z };
}

inline vec3 vec3::operator*(const vec3& rhs) const
{
	return{ _x * rhs._x, _y * rhs._y, _z * rhs._z };
}

inline float vec3::dot(const vec3& rhs) const
{
	return _x * rhs._x + _y * rhs._y + _z * rhs._z;
}

inline vec3& vec3::normalize()
{
	float inv_length = 1.f / sqrtf(_x * _x + _y * _y + _z * _z);
	_x *= inv_length;
	_y *= inv_length;
	_z *= inv_length;
	return *this;
}
