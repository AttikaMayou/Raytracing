#pragma once

#include <iostream>
#include "Intersects.h"

class RectXY : public Intersects {
public:
	RectXY();
	RectXY(float _x0, float _x1, float _y0, float _y1, float _k, Material* mat);
	RectXY(const RectXY& copy);
	~RectXY();
	RectXY& operator=(const RectXY& r);
	virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;

private:
	float x0;
	float x1;
	float y0;
	float y1;
	float k;
	Material* material;
};

class RectXZ : public Intersects {
public:
	RectXZ();
	RectXZ(float _x0, float _x1, float _z0, float _z1, float _k, Material* mat);
	RectXZ(const RectXZ& copy);
	~RectXZ();
	RectXZ& operator=(const RectXZ& r);
	virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;

private:
	float x0;
	float x1;
	float z0;
	float z1;
	float k;
	Material* material;
};

class RectYZ : public Intersects {
public:
	RectYZ();
	RectYZ(float _y0, float _y1, float _z0, float _z1, float _k, Material* mat);
	RectYZ(const RectYZ& copy);
	~RectYZ();
	RectYZ& operator=(const RectYZ& r);
	virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;

private:
	float y0;
	float y1;
	float z0;
	float z1;
	float k;
	Material* material;
};

class FlipFace : public Intersects {
public:
	FlipFace();
	FlipFace(Intersects* obj);
	FlipFace(const FlipFace& copy);
	~FlipFace();
	FlipFace& operator=(const FlipFace& f);
	virtual bool hit(const Ray& r, float tMin, float tMax, IntersectRecord& intersectRecord) const;

private:
	Intersects* ptr;
};