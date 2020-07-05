#pragma once

#include "Ray.h";

class Camera {
public:
	Camera();
	Ray getRay(float u, float v);
	vec3 origin;
	vec3 lowerLeftCorner;
	vec3 horizontal;
	vec3 vertical;
};