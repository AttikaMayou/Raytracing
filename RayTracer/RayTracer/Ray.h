#pragma once

#include "vec3.h"

//TODO : convertir en classe 
//TODO : faire les getter-setter

struct Ray
{
	vec3 origin;
	float tmin;
	vec3 direction;
	float tmax;

	// calcule la position d'un point (intersection)
	// en fonction d'un paramètre de distance
	inline vec3 evaluate(const float t) const {
		return origin + direction * t;
	}
};
