#pragma once

#include "Intersects.h"

class Scene : public Intersects {
	public:
		Scene();
		Scene(Intersects** l, int n);

		virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;
		//virtual bool boundingbox(float t0, float t1, aabb& box) const;

	private:
		Intersects** list;
		int listSize;
};