#pragma once

#include "Primitive.h"

class Sphere : public Primitive {
private :
	float radius;

public :
	Sphere();
	Sphere(const vec3& p, float r);
	Sphere(const vec3& p, float r, Material* m);
	Sphere(const Sphere& s);
	virtual ~Sphere();
	Sphere& operator=(const Sphere& s);
	float GetRadius() const { return radius; }
	void SetRadius(const float r);

	// retourne la distance d'intersection (t) si le discriminant est positif
	// sinon on retourne une valeur négative (quelconque)
	float Intersect(const Ray& ray) const override;
	
	virtual vec3 CalcNormal(const vec3& p) const override;
};
