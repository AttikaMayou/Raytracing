#include "bvhNode.h"

int compareXBox(const void* a, const void* b) {
	aabb leftBox, rightBox;

	Hitable* ah = *(Hitable**)a;
	Hitable* bh = *(Hitable**)b;

	if (!ah->boundingbox(0, 0, leftBox) || !bh->boundingbox(0, 0, rightBox)) {
		std::cerr << "No bounding box" << std::endl;
	}

	if (leftBox.GetMin().getX() - rightBox.GetMin().getX() < 0.0) {
		return -1;
	}
	else {
		return 1;
	}
}

int compareYBox(const void* a, const void* b) {
	aabb leftBox, rightBox;

	Hitable* ah = *(Hitable**)a;
	Hitable* bh = *(Hitable**)b;

	if (!ah->boundingbox(0, 0, leftBox) || !bh->boundingbox(0, 0, rightBox)) {
		std::cerr << "No bounding box" << std::endl;
	}

	if (leftBox.GetMin().getY() - rightBox.GetMin().getY() < 0.0) {
		return -1;
	}
	else {
		return 1;
	}
}

int compareZBox(const void* a, const void* b) {
	aabb leftBox, rightBox;

	Hitable* ah = *(Hitable**)a;
	Hitable* bh = *(Hitable**)b;

	if (!ah->boundingbox(0, 0, leftBox) || !bh->boundingbox(0, 0, rightBox)) {
		std::cerr << "No bounding box" << std::endl;
	}

	if (leftBox.GetMin().getZ() - rightBox.GetMin().getZ() < 0.0) {
		return -1;
	}
	else {
		return 1;
	}
}

bvhNode::bvhNode(Hitable** list, int n, float time0, float time1) {
	int axis = int(3 * Utils::randFloat());

	if (axis == 0) {
		qsort(list, n, sizeof(Hitable*), compareXBox);
	}
	else if (axis == 1) {
		qsort(list, n, sizeof(Hitable*), compareYBox);
	}
	else {
		qsort(list, n, sizeof(Hitable*), compareZBox);
	}

	if (n == 1) {
		left = right = list[0];
	}
	else if (n == 2) {
		left = list[0];
		right = list[1];
	}
	else {
		left = new bvhNode(list, n / 2, time0, time1);
		right = new bvhNode(list + n/2, n - n / 2, time0, time1);
	}

	aabb boxLeft, boxRight;
	if (!left->boundingbox(time0, time1, boxLeft) || !right->boundingbox(time0, time1, boxRight)) {
		std::cout << "No bounding box in bvhNode" << std::endl;
	}

	box = surroundingBox(boxLeft, boxRight);
}

bool bvhNode::boundingbox(float t0, float t1, aabb& newBox) const {
	newBox = box;

	return true;
}

bool bvhNode::hit(const Ray& r, float tMin, float tMax, HitRecord& hitRecord) const {
	if (box.hit(r, tMin, tMax)) {
		HitRecord leftRecord, rightRecord;
		bool hitLeft = left->hit(r, tMin, tMax, leftRecord);
		bool hitRight = right->hit(r, tMin, tMax, rightRecord);

		if (hitLeft && hitRight) {
			if (leftRecord.t < rightRecord.t) {
				hitRecord = leftRecord;
			}
			else {
				hitRecord = rightRecord;
			}

			return true;
		}
		else if (hitLeft) {
			hitRecord = leftRecord;

			return true;
		}
		else if (hitRight) {
			hitRecord = rightRecord;

			return true;
		}
		else {
			return false;
		}
	}

	return false;
}