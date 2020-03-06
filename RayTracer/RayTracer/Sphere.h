#pragma once

#include "Primitive.h"

//TODO : g�rer l'h�ritage depuis "Primitive"

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
	vec3 GetPosition() { return position; }
	float GetRadius() { return radius; }
	Material* GetMaterial() { return mat; }
	void SetPosition(const vec3& p);
	void SetRadius(const float r);
	void SetMaterial(Material* m);

	// retourne la distance d'intersection (t) si le discriminant est positif
	// sinon on retourne une valeur n�gative (quelconque)
	float intersect(const Ray& ray) const final {}

	virtual vec3 calcNormal(const vec3& p) const final {}
};
