#pragma once

#include "Primitive.h"

class Plane : public Primitive
{
private :
	vec3 axe;

public :
	Plane();
	Plane(const vec3& p, const vec3& a);
	Plane(const vec3& p, const vec3& a, Material* m);
	Plane(const Plane& p);
	virtual ~Plane();

	Plane& operator=(const Plane& p);
	vec3 GetAxe() const { return axe; };
	void SetAxe(const vec3& a);

	bool Intersect(const Ray& ray, vec3& impact) const override;
	virtual vec3 CalcNormal(const vec3& p) const override;	
};