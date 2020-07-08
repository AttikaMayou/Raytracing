#pragma once

#include "Material.h"
#include "Utils.h"
#include "Texture.h"

class Lambertian : public Material {
public:
	Lambertian(Texture* a);
	virtual bool scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const;

private:
	Texture *albedo;
};