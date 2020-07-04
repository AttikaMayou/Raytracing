#pragma once

#include "Material.h"
#include "Ray.h"

//TODO : faire une classe parent de Primitive pour gérer les light (pas de normal pour elles)

class Primitive {

private :
protected : 
	Material* mat = nullptr;
public :
	Primitive();
	Primitive(Material* m);
	Primitive(const Primitive& p);
	Primitive& operator=(const Primitive& p);
	Material* GetMaterial();
	void SetMaterial(Material* m);
	
	virtual float intersect(const Ray& ray) const = 0;
	virtual vec3 calcNormal(const vec3& p) const = 0;
	virtual ~Primitive();
};
