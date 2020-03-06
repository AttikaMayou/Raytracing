#pragma once

#include "Primitive.h"

//TODO : faire les getter-setter
//TODO : gérer l'héritage depuis "Primitive"

class Sphere : public Primitive {
private :
	vec3 position;
	float radius;
	Material* mat;

public :
	Sphere();
	Sphere(const vec3& p, float r);
	Sphere(const vec3& p, float r, Material* m);
	virtual ~Sphere();
	float intersect(const Ray& ray) const final {}
	virtual vec3 calcNormal(const vec3& p) const final {}
};
