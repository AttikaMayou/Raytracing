#pragma once

#include <iostream>
#include <vector>
#include "Intersects.h"

using namespace std;

class ObjectsList : public Intersects {
	public:
		ObjectsList();
		ObjectsList(vector<Intersects*> l);
		ObjectsList(const ObjectsList& copy);
		~ObjectsList();
		ObjectsList& operator=(const ObjectsList& o);

		void Add(Intersects* obj);
		virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;
		//virtual bool boundingbox(float t0, float t1, aabb& box) const;

	private:
		vector<Intersects*> list;
		int listSize;
};