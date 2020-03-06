#pragma once

#include <cmath>

struct vec3
{
	union
	{
		struct {
			float x, y, z;
		};
		struct {
			float r, g, b;
		};
	};

	inline vec3 operator*(const float t) const {
		return{ x*t, y*t, z*t };
	}

	inline vec3 operator+(const vec3& rhs) const {
		return{ x + rhs.x, y + rhs.y, z + rhs.z };
	}

	inline vec3 operator-(const vec3& rhs) const {
		return{ x - rhs.x, y - rhs.y, z - rhs.z };
	}

	inline vec3 operator*(const vec3& rhs) const {
		return{ x * rhs.x, y * rhs.y, z * rhs.z };
	}

	inline float dot(const vec3& rhs) const {
		return x*rhs.x + y*rhs.y + z*rhs.z;
	}

	inline vec3& normalize() {
		float inv_length = 1.f / sqrtf(x*x + y*y + z*z);
		x *= inv_length;
		y *= inv_length;
		z *= inv_length;
		return *this;
	}
};

// equivalent a typedef vec3 color;
using color = vec3;
