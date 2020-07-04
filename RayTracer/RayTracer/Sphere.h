#pragma once

#include "Primitive.h"

//TODO : gérer l'héritage depuis "Primitive"

class Sphere : public Primitive {
private :
	vec3 position;
	float radius;

public :
	Sphere();
	Sphere(const vec3& p, float r);
	Sphere(const vec3& p, float r, Material* m);
	Sphere(const Sphere& s);
	virtual ~Sphere();
	Sphere& operator=(const Sphere& s);
	vec3 GetPosition() const { return position; }
	float GetRadius() const { return radius; }
	const Material* GetMaterial() const { return mat; }
	void SetPosition(const vec3& p);
	void SetRadius(const float r);

	// retourne la distance d'intersection (t) si le discriminant est positif
	// sinon on retourne une valeur négative (quelconque)
	float intersect(const Ray& ray) const;
	
	virtual vec3 calcNormal(const vec3& p) const;
};
