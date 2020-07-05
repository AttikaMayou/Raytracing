#pragma once

#include "Light.h"

class DirectionalLight : Light {

private :

public :
	DirectionalLight() : Light() {}
	DirectionalLight(const vec3& p, const vec3& d) : Light(p, d) {}
	DirectionalLight(const DirectionalLight& d);
	~DirectionalLight();
	DirectionalLight& operator=(const DirectionalLight& d);

};
