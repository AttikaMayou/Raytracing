#pragma once

#include "Primitive.h"

//TODO : g�rer l'h�ritage depuis "Primitive"

class Sphere : public Primitive {
private :
	vec3 position;
	float radius;

public :
	Sphere();
	Sphere(const vec3& p, float r);
	Sphere(const vec3& p, float r, const  Material* m);
	virtual ~Sphere();
	vec3 GetPosition() const { return position; }
	float GetRadius() const { return radius; }
	const Material* GetMaterial() const { return mat; }
	void SetPosition(const vec3& p);
	void SetRadius(const float r);
	void SetMaterial(const Material* m);

	// retourne la distance d'intersection (t) si le discriminant est positif
	// sinon on retourne une valeur n�gative (quelconque)
	float intersect(const Ray& ray) const;
	
	virtual vec3 calcNormal(const vec3& p) const;
};
