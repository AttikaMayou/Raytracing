#pragma once

#include "Material.h"
#include "Ray.h"

//TODO : faire les getter-setter
//TODO : faire une classe parent de Primitive pour gérer les light (pas de normal pour elles)

class Primitive {

private :

public :
	Primitive() {}
	~Primitive() {}
	virtual float intersect(const Ray& ray) const = 0;
	virtual vec3 calcNormal(const vec3& p) const = 0;
	virtual ~Primitive() {}
};
