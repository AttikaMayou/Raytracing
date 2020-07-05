#pragma once

#include "Primitive.h"

class Cylinder : public Primitive
{
private:
	vec3 position;
	vec3 axe;
	float radius;

public :
	Cylinder();
	Cylinder(const vec3& p, const vec3 a, const float r);
	Cylinder(const vec3& p, const vec3 a, const float r, Material* m);
	Cylinder(const Cylinder& c);
	virtual ~Cylinder();

	Cylinder& operator=(const Cylinder& c);
	vec3 GetPosition() const { return position; };
	vec3 GetAxe() const { return axe; };
	float GetRadius() const { return radius; };
	void SetPosition(const vec3& p);
	void SetAxe(const vec3& a);
	void SetRadius(const float r);

	float Intersect(const Ray& ray) const override;
	virtual vec3 CalcNormal(const vec3& p) const override;
	
};
