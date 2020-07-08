#include "aabb.h"

aabb surroundingBox(aabb box0, aabb box1) {
	vec3 small(
		fmin(box0.GetMin().getX(), box1.GetMin().getX()), 
		fmin(box0.GetMin().getY(), box1.GetMin().getY()),
		fmin(box0.GetMin().getZ(), box1.GetMin().getZ())
	);

	vec3 big(
		fmin(box0.GetMax().getX(), box1.GetMax().getX()),
		fmin(box0.GetMax().getY(), box1.GetMax().getY()),
		fmin(box0.GetMax().getZ(), box1.GetMax().getZ())
	);

	return aabb(small, big);
}