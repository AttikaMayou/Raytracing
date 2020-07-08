/*#pragma once

#include "Hitable.h"
#include "Utils.h"

class bvhNode : public Hitable {
public:
	bvhNode() {}
	bvhNode(Hitable** list, int n, float time0, float time1);
	virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& hitRecord) const;
	virtual bool boundingbox(float t0, float t1, aabb& box) const;

private:
	Hitable* left;
	Hitable* right;
	aabb box;
};*/