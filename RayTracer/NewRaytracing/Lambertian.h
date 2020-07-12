#pragma once

#include "Material.h"
#include "Utils.h"
#include "Texture.h"

class Lambertian : public Material {
public:
	Lambertian();
	Lambertian(Texture* a);
	Lambertian(const Lambertian& copy);
	~Lambertian();
	Lambertian& operator=(const Lambertian& l);
	virtual bool scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const;

private:
	Texture *albedo;
};