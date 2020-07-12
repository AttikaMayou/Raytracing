#include "Faces.h"

RectXY::RectXY() : x0(0.f), x1(0.f), y0(0.f), y1(0.f), k(0.f)
{
	material = nullptr;
}

// X - Y face
RectXY::RectXY(float _x0, float _x1, float _y0, float _y1, float _k, Material* mat) : x0(_x0), x1(_x1), y0(_y0), y1(_y1), k(_k), material(mat) {}

RectXY::RectXY(const RectXY& copy)
{
	x0 = copy.x0;
	x1 = copy.x1;
	y0 = copy.y0;
	y1 = copy.y1;
	k = copy.k;
	material = copy.material;
}

RectXY::~RectXY()
{
	//delete material;
}

RectXY& RectXY::operator=(const RectXY& r)
{
	x0 = r.x0;
	x1 = r.x1;
	y0 = r.y0;
	y1 = r.y1;
	k = r.k;
	material = r.material;
	return *this;
}

bool RectXY::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const
{
	float t = (k - r.getOrigine().getZ()) / (r.getDirection().getZ());

	if (t < tMin || t > tMax) {
		return false;
	}

	float x = r.getOrigine().getX() + t * r.getDirection().getX();
	float y = r.getOrigine().getY() + t * r.getDirection().getY();

	if (x < x0 || x > x1 || y < y0 || y > y1) {
		return false;
	}

	intersectRecord.u = (x - x0) / (x1 - x0);
	intersectRecord.v = (y - y0) / (y1 - y0);
	intersectRecord.t = t;

	vec3 outNormal = vec3(0, 0, 1);
	intersectRecord.setNormal(r, outNormal);
	intersectRecord.mat = material;
	intersectRecord.point = r.pointAtParamater(t);

	return true;
}

RectXZ::RectXZ() : x0(0.f), x1(0.f), z0(0.f), z1(0.f), k(0.f)
{
	material = nullptr;
}

// X - Z face
RectXZ::RectXZ(float _x0, float _x1, float _z0, float _z1, float _k, Material* mat) : x0(_x0), x1(_x1), z0(_z0), z1(_z1), k(_k), material(mat) {}

RectXZ::RectXZ(const RectXZ& copy)
{
	x0 = copy.x0;
	x1 = copy.x1;
	z0 = copy.z0;
	z1 = copy.z1;
	k = copy.k;
	material = copy.material;
}

RectXZ::~RectXZ()
{
	//delete material;
}

RectXZ& RectXZ::operator=(const RectXZ& r)
{
	x0 = r.x0;
	x1 = r.x1;
	z0 = r.z0;
	z1 = r.z1;
	k = r.k;
	material = r.material;
	return *this;
}

bool RectXZ::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const
{
	float t = (k - r.getOrigine().getY()) / (r.getDirection().getY());

	if (t < tMin || t > tMax) {
		return false;
	}

	float x = r.getOrigine().getX() + t * r.getDirection().getX();
	float z = r.getOrigine().getZ() + t * r.getDirection().getZ();

	if (x < x0 || x > x1 || z < z0 || z > z1) {
		return false;
	}

	intersectRecord.u = (x - x0) / (x1 - x0);
	intersectRecord.v = (z - z0) / (z1 - z0);
	intersectRecord.t = t;

	vec3 outNormal = vec3(0, 1, 0);
	intersectRecord.setNormal(r, outNormal);
	intersectRecord.mat = material;
	intersectRecord.point = r.pointAtParamater(t);

	return true;
}

RectYZ::RectYZ() : y0(0.f), y1(0.f), z0(0.f), z1(0.f), k(0.f)
{
	material = nullptr;
}

// Y - Z face
RectYZ::RectYZ(float _y0, float _y1, float _z0, float _z1, float _k, Material* mat) : y0(_y0), y1(_y1), z0(_z0), z1(_z1), k(_k), material(mat) {}

RectYZ::RectYZ(const RectYZ& copy)
{
	y0 = copy.y0;
	y1 = copy.y1;
	z0 = copy.z0;
	z1 = copy.z1;
	k = copy.k;
	material = copy.material;
}

RectYZ::~RectYZ()
{
	//delete material;
}

RectYZ& RectYZ::operator=(const RectYZ& r)
{
	y0 = r.y0;
	y1 = r.y1;
	z0 = r.z0;
	z1 = r.z1;
	k = r.k;
	material = r.material;
	return *this;
}

bool RectYZ::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const
{
	float t = (k - r.getOrigine().getX()) / (r.getDirection().getX());

	if (t < tMin || t > tMax) {
		return false;
	}

	float y = r.getOrigine().getY() + t * r.getDirection().getY();
	float z = r.getOrigine().getZ() + t * r.getDirection().getZ();

	if (y < y0 || y > y1 || z < z0 || z > z1) {
		return false;
	}

	intersectRecord.u = (y - y0) / (y1 - y0);
	intersectRecord.v = (z - z0) / (z1 - z0);
	intersectRecord.t = t;

	vec3 outNormal = vec3(1, 0, 0);
	intersectRecord.setNormal(r, outNormal);
	intersectRecord.mat = material;
	intersectRecord.point = r.pointAtParamater(t);

	return true;
}

FlipFace::FlipFace() : ptr(nullptr) {}

FlipFace::FlipFace(Intersects* obj) : ptr(obj) {}

FlipFace::FlipFace(const FlipFace& copy)
{
	ptr = copy.ptr;
}

FlipFace::~FlipFace()
{
	delete ptr;
}

FlipFace& FlipFace::operator=(const FlipFace& f)
{
	ptr = f.ptr;
	return *this;
}

bool FlipFace::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const {
	if (!ptr->hit(r, tMin, tMax, intersectRecord)) {
		return false;
	}

	intersectRecord.frontFace = !intersectRecord.frontFace;
	return true;
}
