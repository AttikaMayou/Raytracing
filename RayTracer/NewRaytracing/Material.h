#pragma once

#include "Intersects.h"

class Material {
public:
	Material();
	virtual bool scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const = 0;
	virtual vec3 emitted(float u, float v, const vec3& point) const;
};