#include "Lambertian.h"

Lambertian::Lambertian() : albedo(nullptr) {}

Lambertian::Lambertian(Texture* a) : albedo(a) {}

Lambertian::Lambertian(const Lambertian& copy) : albedo(copy.albedo) {}

Lambertian::~Lambertian()
{
	delete albedo;
}

Lambertian& Lambertian::operator=(const Lambertian& l)
{
	albedo = l.albedo;
	return* this;
}

bool Lambertian::scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const {
	vec3 target = rec.point + rec.normal + Utils::randInUnitSphere();

	scattered = Ray(rec.point, target - rec.point);
	attenuation = albedo->value(0, 0, rec.point);

	return true;
}
