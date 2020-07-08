#include "ObjectsList.h"

ObjectsList::ObjectsList() {

}

ObjectsList::ObjectsList(vector<Intersects*> l) {
	list = l;
	listSize = l.size();
}

bool ObjectsList::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const {
	IntersectRecord tempRecord;
	bool intersectAnything = false;
	double closestSoFar = tMax;

	for (int i = 0; i < listSize; i++) {
		if (list[i]->hit(r, tMin, closestSoFar, tempRecord)) {
			intersectAnything = true;
			closestSoFar = tempRecord.t;
			intersectRecord = tempRecord;
		}
	}

	return intersectAnything;
}


void ObjectsList::Add(Intersects* obj) {
	list.push_back(obj);
	listSize = list.size();
}