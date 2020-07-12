#pragma once

#include "Material.h"
#include "Utils.h"

class Dielectric : public Material {
public:
	Dielectric();
	Dielectric(float ri);
	Dielectric(const Dielectric& copy);
	~Dielectric();
	Dielectric& operator=(const Dielectric& d);
	virtual bool scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const;

private:
	float refIdx;
};