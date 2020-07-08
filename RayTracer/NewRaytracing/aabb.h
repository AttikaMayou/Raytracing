/*#pragma once

#include <iostream>
#include "Ray.h"

inline float ffmin(float a, float b) {
	return a < b ? a : b;
}

inline float ffmax(float a, float b) {
	return a > b ? a : b;
}

class aabb {
public:
	aabb() {}
	aabb(const vec3& a, const vec3& b) {
		min = a;
		max = b;
	}

	vec3 GetMin() const {
		return min;
	}

	vec3 GetMax() const {
		return max;
	}

	bool hit(const Ray& ray, float tMin, float tMax) const {
		for (int i = 0; i < 3; ++i) {
			float t0 = ffmin((min[i] - ray.getOrigine()[i]) / ray.getDirection()[i], (min[i] - ray.getOrigine()[i]) / ray.getDirection()[i]);
			float t1 = ffmax((min[i] - ray.getOrigine()[i]) / ray.getDirection()[i], (min[i] - ray.getOrigine()[i]) / ray.getDirection()[i]);

			tMin = ffmax(t0, tMin);
			tMax = ffmin(t1, tMax);

			if (tMax <= tMin) {
				return false;
			}
		}

		return true;
	}

private:
	vec3 min;
	vec3 max;
};

aabb surroundingBox(aabb box0, aabb box1);
*/

/*inline bool aabb::hit(const Ray& ray, float tMin, float tMax) const {
	for (int i = 0; i < 3; i++) {
		float invD = 1.0f / ray.getDirection()[i];
		float t0 = (GetMin()[i] - ray.getOrigine()[i]) * invD;
		float t1 = (GetMax()[i] - ray.getOrigine()[i]) * invD;

		if (invD < 0.0f) {
			std::swap(t0, t1);
		}

		tMin = t0 > tMin ? t0 : tMin;
		tMax = t1 < tMax ? t1 : tMax;

		if (tMax <= tMin) {
			return false;
		}
	}

	return true;
}*/