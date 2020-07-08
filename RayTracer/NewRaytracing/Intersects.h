#pragma once

#include "Ray.h"

class Material;

struct IntersectRecord {
	float t;
	float u;
	float v;
	bool frontFace;
	vec3 point;
	vec3 normal;
	Material* mat;
	
	inline void setNormal(const Ray& ray, const vec3& outNormal) {
		frontFace = dot(ray.getDirection(), outNormal) < 0;
		normal = frontFace ? outNormal : outNormal * -1;
	}
};

class Intersects {
	public:
		virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const = 0;
		//virtual bool boundingbox(float t0, float t1, aabb& box) const = 0;
};