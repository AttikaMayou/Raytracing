#pragma once

#include "Intersects.h"
#include "Material.h"
#include "Utils.h"

class Sphere : public Intersects {
	public:
		Sphere();
		Sphere(const vec3& cen, float r, Material* m);
		~Sphere();
		Sphere(const Sphere& copy);
		Sphere& operator=(const Sphere& s);

		virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;

		vec3 GetCenter();
		float GetRadius();

	private:
		vec3 center;
		float radius;
		Material* mat;
};