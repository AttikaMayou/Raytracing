#pragma once

#include "Light.h"

class DirectionalLight : Light {

private :
	vec3 position;
	vec3 direction;

public :
	DirectionalLight() : position(vec3{ 0.f, 0.f, 0.f }), direction(vec3{ 0.f, 0.f, 0.f }) {}
	DirectionalLight(vec3 p, vec3 d) : position(p), direction(d) {}
	~DirectionalLight();

};
