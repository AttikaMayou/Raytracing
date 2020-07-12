#pragma once

#include "Material.h"
#include "Texture.h"

class DiffuseLight : public Material {
public:
	DiffuseLight();
	DiffuseLight(Texture* tex);
	DiffuseLight(const DiffuseLight& copy);
	~DiffuseLight();
	DiffuseLight& operator=(const DiffuseLight& d);

	virtual bool scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const;
	virtual vec3 emitted(float u, float v, const vec3& point) const;

private:
	Texture* emit;
};