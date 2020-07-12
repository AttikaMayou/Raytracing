#include "DiffuseLight.h"

DiffuseLight::DiffuseLight() : emit(nullptr) {}

DiffuseLight::DiffuseLight(Texture* tex) : emit(tex) {}

DiffuseLight::DiffuseLight(const DiffuseLight& copy) : emit(copy.emit) {}

DiffuseLight::~DiffuseLight()
{
	delete emit;
}

DiffuseLight& DiffuseLight::operator=(const DiffuseLight& d)
{
	emit = d.emit;
	return *this;
}

bool DiffuseLight::scatter(const Ray& rayIn, const IntersectRecord& rec, vec3& attenuation, Ray& scattered) const {
	return false;
}

vec3 DiffuseLight::emitted(float u, float v, const vec3& point) const {
	return emit->value(u, v, point);
}