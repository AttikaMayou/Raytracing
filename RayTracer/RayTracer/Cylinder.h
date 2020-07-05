#pragma once

#include "Primitive.h"

class Cylinder : public Primitive
{
private:
	vec3 axe;
	float radius;

public :
	Cylinder();
	Cylinder(const vec3& p, const vec3 a, const float r);
	Cylinder(const vec3& p, const vec3 a, const float r, Material* m);
	Cylinder(const Cylinder& c);
	virtual ~Cylinder();

	Cylinder& operator=(const Cylinder& c);
	vec3 GetAxe() const { return axe; };
	float GetRadius() const { return radius; };
	void SetAxe(const vec3& a);
	void SetRadius(const float r);

	float Intersect(const Ray& ray) const override;
	virtual vec3 CalcNormal(const vec3& p) const override;
	
};
