#include "Scene.h"

Scene::Scene() {

}

Scene::Scene(Intersects** l, int n) {
	list = l;
	listSize = n;
}

bool Scene::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const {
	IntersectRecord tempRecord;
	bool hitAnything = false;
	double closestSoFar = tMax;

	for (int i = 0; i < listSize; i++) {
		if (list[i]->hit(r, tMin, closestSoFar, tempRecord)) {
			hitAnything = true;
			closestSoFar = tempRecord.t;
			intersectRecord = tempRecord;
		}
	}

	return hitAnything;
}
/*
bool Scene::boundingbox(float t0, float t1, aabb& box) const {
	if (listSize < 1) {
		return false;
	}

	aabb tempBox;
	bool firstTrue = list[0]->boundingbox(t0, t1, tempBox);

	if (!firstTrue) {
		return false;
	}
	else {
		box = tempBox;
	}

	for (int i = 1; i < listSize; i++) {
		if (list[i]->boundingbox(t0, t1, tempBox)) {
			box = surroundingBox(box, tempBox);
		}
		else {
			return false;
		}
	}

	return true;
}*/