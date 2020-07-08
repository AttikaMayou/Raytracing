#include "DiffuseLight.h"

DiffuseLight::DiffuseLight() {}
DiffuseLight::DiffuseLight(Texture* tex) : emit(tex) {}

bool DiffuseLight::scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const {
	return false;
}

vec3 DiffuseLight::emitted(float u, float v, const vec3& point) const {
	return emit->value(u, v, point);
}