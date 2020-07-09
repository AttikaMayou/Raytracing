#include "Utils.h"

float Utils::randFloat() {
	return (double)rand() / (RAND_MAX + 1.0);
}

float Utils::randFloat(int min, int max) {
	return min + (max - min) * randFloat();
}

vec3 Utils::randInUnitDisk() {
	while (true) {
		auto p = vec3(Utils::randFloat(-1, 1), Utils::randFloat(-1, 1), 0);
		if (p.squareLenght() >= 1) continue;
		return p;
	}
}

vec3 Utils::randInUnitSphere() {
	vec3 p;
	do {
		p = vec3(Utils::randFloat(), Utils::randFloat(), Utils::randFloat()) * 2 - vec3(1, 1, 1);
	} while (p.squareLenght() >= 1.0);

	return p;
}

vec3 Utils::reflect(const vec3& v, const vec3& n) {
	return v - n * dot(v, n) * 2;
}

bool Utils::refract(const vec3& v, const vec3& n, float niOverNt, vec3& refracted) {
	vec3 uv = unitVector(v);
	float dt = dot(uv, n);
	float t = 1.0 - niOverNt * niOverNt * (1 - dt * dt);

	if (t > 0) {
		refracted = (uv - n * dt) * niOverNt - n * sqrt(t);
		return true;
	}

	return false;
}

float Utils::schlick(float cosine, float refIdx) {
	float r0 = (1 - refIdx) / (1 + refIdx);
	r0 = r0 * r0;

	return r0 + (1 - r0) * pow((1 - cosine), 5);
}

void Utils::getSphereUv(const vec3& point, float& u, float& v) {
	float phi = atan2(point.getZ(), point.getX());
	float theta = asin(point.getY());

	u = 1 - (phi + M_PI) / (2 * M_PI);
	v = (theta + M_PI / 2) / M_PI;
}