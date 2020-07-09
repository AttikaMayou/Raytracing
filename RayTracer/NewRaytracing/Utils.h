#pragma once

#define _USE_MATH_DEFINES // for C++
#include <cmath>

#define M_PI       3.14159265358979323846   // pi

#include <stdlib.h>
#include <time.h>

#include "vec3.h"

class Utils {
public:
	static float randFloat();

	static float randFloat(int min, int max);

	static vec3 randInUnitDisk();

	static vec3 randInUnitSphere();

	static vec3 reflect(const vec3& v, const vec3& n);

	static bool refract(const vec3& v, const vec3& n, float niOverNt, vec3& refracted);

	static float schlick(float cosine, float refIdx);

	static void getSphereUv(const vec3& point, float& u, float& v);
};