#include "Faces.h"

// X - Y face
RectXY::RectXY(float _x0, float _x1, float _y0, float _y1, float _k, Material* mat) : x0(_x0), x1(_x1), y0(_y0), y1(_y1), k(_k), material(mat) {

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

// X - Z face
RectXZ::RectXZ(float _x0, float _x1, float _z0, float _z1, float _k, Material* mat) : x0(_x0), x1(_x1), z0(_z0), z1(_z1), k(_k), material(mat) {

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

// Y - Z face
RectYZ::RectYZ(float _y0, float _y1, float _z0, float _z1, float _k, Material* mat) : y0(_y0), y1(_y1), z0(_z0), z1(_z1), k(_k), material(mat) {

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

FlipFace::FlipFace(Intersects* obj) : ptr(obj) {

}

bool FlipFace::hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const {
	if (!ptr->hit(r, tMin, tMax, intersectRecord)) {
		return false;
	}

	intersectRecord.frontFace = !intersectRecord.frontFace;
	return true;
}