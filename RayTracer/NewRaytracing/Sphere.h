#pragma once

#include "Intersects.h"
#include "Material.h"
#include "Utils.h"

class Sphere : public Intersects {
	public:
		Sphere();

		Sphere(vec3 cen, float r, Material* m);

		virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;

		vec3 GetCenter();
		float GetRadius();

	private:
		vec3 center;
		float radius;
		Material* mat;
};