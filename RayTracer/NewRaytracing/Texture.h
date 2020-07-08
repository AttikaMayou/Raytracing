#pragma once

#include "vec3.h"

class Texture {
public:
	virtual vec3 value(float u, float v, const vec3& p) const = 0;
};