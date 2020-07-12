#pragma once

#define _USE_MATH_DEFINES // for C++
#include <cmath>

#include "Ray.h";
#include "Utils.h";

class Camera {
public:
	Camera();
	Camera(vec3 lookFrom, vec3 lookAt, vec3 vup, float vfov, float aspect, float aperture, float focusDist, float t0, float t1);
	Camera(const Camera& copy);
	~Camera();
	Camera& operator=(const Camera& c);
	Ray getRay(float u, float v) const;

private:
	vec3 origin;
	vec3 lowerLeftCorner;
	vec3 horizontal;
	vec3 vertical;
	vec3 u;
	vec3 v;
	vec3 w;

	float lensRadius;
	float time0;
	float time1;
};