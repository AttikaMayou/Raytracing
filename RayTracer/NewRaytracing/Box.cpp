#include "Box.h"

Box::Box(const vec3& point0, const vec3& point1, Material* mat) : boxMin(point0), boxMax(point1) {
	faces.Add(new RectXY(point0.getX(), point1.getX(), point0.getY(), point1.getY(), point1.getZ(), mat));
	faces.Add(new FlipFace(new RectXY(point0.getX(), point1.getX(), point0.getY(), point1.getY(), point0.getZ(), mat)));

	faces.Add(new RectXZ(point0.getX(), point1.getX(), point0.getZ(), point1.getZ(), point1.getY(), mat));
	faces.Add(new FlipFace(new RectXY(point0.getX(), point1.getX(), point0.getZ(), point1.getZ(), point0.getY(), mat)));

	faces.Add(new RectYZ(point0.getY(), point1.getY(), point0.getZ(), point1.getZ(), point1.getX(), mat));
	faces.Add(new FlipFace(new RectXY(point0.getY(), point1.getY(), point0.getZ(), point1.getZ(), point0.getX(), mat)));
}

bool Box::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const
{
	return faces.hit(r, tMin, tMax, intersectRecord);
}
