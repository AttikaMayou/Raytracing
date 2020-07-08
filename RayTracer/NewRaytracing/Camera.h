#pragma once

#define _USE_MATH_DEFINES // for C++
#include <cmath>

#include "Ray.h";

class Camera {
public:
	Camera(vec3 lookFrom, vec3 lookAt, vec3 vup, float vfov, float aspect);
	Ray getRay(float u, float v) const;
	vec3 origin;
	vec3 lowerLeftCorner;
	vec3 horizontal;
	vec3 vertical;
};