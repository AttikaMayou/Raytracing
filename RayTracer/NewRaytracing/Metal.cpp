#include "Metal.h"

Metal::Metal(const vec3& a, float f) : albedo(a) {
	if (f < 1) {
		fuzz = f;
	}
	else {
		fuzz = 1;
	}
}

bool Metal::scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const {
	vec3 reflected = Utils::reflect(unitVector(rayIn.getDirection()), rec.normal);
	scattered = Ray(rec.point, reflected + Utils::randInUnitSphere() * fuzz);
	attenuation = albedo;

	return (dot(scattered.getDirection(), rec.normal) > 0);
}