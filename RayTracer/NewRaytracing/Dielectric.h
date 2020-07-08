#pragma once

#include "Material.h"
#include "Utils.h"

class Dielectric : public Material {
public:
	Dielectric(float ri);
	virtual bool scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const;

private:
	float refIdx;
};