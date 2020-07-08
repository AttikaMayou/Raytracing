#include "Sphere.h"

Sphere::Sphere() {}

Sphere::Sphere(vec3 cen, float r, Material* m) : center(cen), radius(r), mat(m) {}

bool Sphere::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const {
	vec3 rayDirection = r.getDirection();
	vec3 rayOrigin = r.getOrigine();
	vec3 oc = rayOrigin - center;

	float a = dot(rayDirection, rayDirection);
	float b = dot(oc, rayDirection);

	float c = dot(oc, oc) - radius * radius;
	float t = pow(b, 2) - (a * c);

	if (t >= 0.f) {
		float temp = (-b - sqrt(b * b - a * c)) / a;

		if (temp < tMax && temp > tMin) {
			intersectRecord.t = temp;
			intersectRecord.point = r.pointAtParamater(intersectRecord.t);

			vec3 outNormal = (intersectRecord.point - center) / radius;
			intersectRecord.setNormal(r, outNormal);
			Utils::getSphereUv((intersectRecord.point - center), intersectRecord.u, intersectRecord.v);

			intersectRecord.mat = mat;
			return true;
		}

		temp = (-b + sqrt(b * b - a * c)) / a;
		if (temp < tMax && temp > tMin) {
			intersectRecord.t = temp;
			intersectRecord.point = r.pointAtParamater(intersectRecord.t);

			vec3 outNormal = (intersectRecord.point - center) / radius;
			intersectRecord.setNormal(r, outNormal);
			Utils::getSphereUv((intersectRecord.point - center), intersectRecord.u, intersectRecord.v);

			intersectRecord.mat = mat;
			return true;
		}
	}

	return false;
}

vec3 Sphere::GetCenter() { 
	return center; 
}

float Sphere::GetRadius() { 
	return radius; 
}