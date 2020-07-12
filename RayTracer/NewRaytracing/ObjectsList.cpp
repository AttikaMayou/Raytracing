#include "ObjectsList.h"

ObjectsList::ObjectsList() : listSize(0) {}

ObjectsList::ObjectsList(vector<Intersects*> l) {
	list = l;
	listSize = l.size();
}

ObjectsList::ObjectsList(const ObjectsList& copy): listSize(copy.listSize)
{
	list = copy.list;
}

ObjectsList::~ObjectsList()
{
	for(int i = 0; i < listSize; ++i)
	{
		delete list[i];
	}
}

ObjectsList& ObjectsList::operator=(const ObjectsList& o)
{
	listSize = o.listSize;
	list = o.list;
	return *this;
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