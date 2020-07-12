#include "Metal.h"

Metal::Metal() : albedo({ 0.f, 0.f, 0.f }), fuzz(0.f) {}

Metal::Metal(const vec3& a, float f) : albedo(a) {
	if (f < 1) {
		fuzz = f;
	}
	else {
		fuzz = 1;
	}
}

Metal::Metal(const Metal& copy) : albedo(copy.albedo), fuzz(copy.fuzz) {}

Metal::~Metal() {}

Metal& Metal::operator=(const Metal& m)
{
	albedo = m.albedo;
	fuzz = m.fuzz;
	return *this;
}

bool Metal::scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const {
	vec3 reflected = Utils::reflect(unitVector(rayIn.getDirection()), rec.normal);
	scattered = Ray(rec.point, reflected + Utils::randInUnitSphere() * fuzz);
	attenuation = albedo;

	return (dot(scattered.getDirection(), rec.normal) > 0);
}
