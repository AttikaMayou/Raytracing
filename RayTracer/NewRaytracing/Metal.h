#pragma once

#include "Material.h"
#include "Utils.h"

class Metal : public Material {
public:
	Metal();
	Metal(const vec3& a, float f);
	Metal(const Metal& copy);
	~Metal();
	Metal& operator=(const Metal& m);
	virtual bool scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const;
private:
	vec3 albedo;
	float fuzz;
};