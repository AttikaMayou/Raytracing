#pragma once

#include "ObjectsList.h"
#include "Material.h"
#include "Faces.h"

class Box : public Intersects {
public:
	Box(Material* mat);
	Box(const vec3& point0, const vec3& point1, Material* mat);
	Box(const Box& copy);
	~Box();
	Box& operator=(const Box& b);
	virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;

private:
	vec3 boxMin;
	vec3 boxMax;
	ObjectsList faces;
};