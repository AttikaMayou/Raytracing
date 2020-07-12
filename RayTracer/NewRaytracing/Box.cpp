#include "Box.h"

Box::Box(Material* mat) : boxMin({ 0, 0, 0 }), boxMax({ 1, 1, 1 })
{
	faces.Add(new RectXY(boxMin.getX(), boxMax.getX(), boxMin.getY(), boxMax.getY(), boxMax.getZ(), mat));
	faces.Add(new FlipFace(new RectXY(boxMin.getX(), boxMax.getX(), boxMin.getY(), boxMax.getY(), boxMin.getZ(), mat)));

	faces.Add(new RectXZ(boxMin.getX(), boxMax.getX(), boxMin.getZ(), boxMax.getZ(), boxMax.getY(), mat));
	faces.Add(new FlipFace(new RectXY(boxMin.getX(), boxMax.getX(), boxMin.getZ(), boxMax.getZ(), boxMin.getY(), mat)));

	faces.Add(new RectYZ(boxMin.getY(), boxMax.getY(), boxMin.getZ(), boxMax.getZ(), boxMax.getX(), mat));
	faces.Add(new FlipFace(new RectXY(boxMin.getY(), boxMax.getY(), boxMin.getZ(), boxMax.getZ(), boxMin.getX(), mat)));
}

Box::Box(const vec3& point0, const vec3& point1, Material* mat) : boxMin(point0), boxMax(point1) {
	faces.Add(new RectXY(point0.getX(), point1.getX(), point0.getY(), point1.getY(), point1.getZ(), mat));
	faces.Add(new FlipFace(new RectXY(point0.getX(), point1.getX(), point0.getY(), point1.getY(), point0.getZ(), mat)));

	faces.Add(new RectXZ(point0.getX(), point1.getX(), point0.getZ(), point1.getZ(), point1.getY(), mat));
	faces.Add(new FlipFace(new RectXY(point0.getX(), point1.getX(), point0.getZ(), point1.getZ(), point0.getY(), mat)));

	faces.Add(new RectYZ(point0.getY(), point1.getY(), point0.getZ(), point1.getZ(), point1.getX(), mat));
	faces.Add(new FlipFace(new RectXY(point0.getY(), point1.getY(), point0.getZ(), point1.getZ(), point0.getX(), mat)));
}

Box::Box(const Box& copy)
{
	boxMin = copy.boxMin;
	boxMax = copy.boxMax;
	faces = copy.faces;
}

Box::~Box()
= default;

Box& Box::operator=(const Box& b)
{
	boxMin = b.boxMin;
	boxMax = b.boxMax;
	faces = b.faces;
	return *this;
}

bool Box::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const
{
	return faces.hit(r, tMin, tMax, intersectRecord);
}
