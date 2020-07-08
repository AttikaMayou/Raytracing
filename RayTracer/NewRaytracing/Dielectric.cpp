#include "Dielectric.h"

Dielectric::Dielectric(float ri) : refIdx(ri) {}

bool Dielectric::scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const {
	vec3 outwardNormal;
	vec3 reflected = Utils::reflect(rayIn.getDirection(), rec.normal);
	float niOverNt;

	attenuation = vec3(1.0, 1.0, 1.0);
	vec3 refracted;
	float reflectProb;
	float cosine;

	if (dot(rayIn.getDirection(), rec.normal) > 0) {
		outwardNormal = rec.normal * -1;
		niOverNt = refIdx;
		cosine = refIdx * dot(rayIn.getDirection(), rec.normal) / rayIn.getDirection().norm();
	}
	else {
		outwardNormal = rec.normal;
		niOverNt = 1.0 / refIdx;
		cosine = -dot(rayIn.getDirection(), rec.normal) / rayIn.getDirection().norm();
	}

	if (Utils::refract(rayIn.getDirection(), outwardNormal, niOverNt, refracted)) {
		reflectProb = Utils::schlick(cosine, refIdx);
	}
	else {
		reflectProb = 1.0;
	}

	if (Utils::randFloat() < reflectProb) {
		scattered = Ray(rec.point, reflected);
	}
	else {
		scattered = Ray(rec.point, refracted);
	}

	return true;
}