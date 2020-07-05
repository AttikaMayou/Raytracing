#pragma once

#include "Material.h"
#include "Ray.h"

class Primitive {

private :
protected : 
	Material* mat = nullptr;
public :
	Primitive();
	Primitive(Material* m);
	Primitive(const Primitive& p);
	Primitive& operator=(const Primitive& p);
	virtual ~Primitive();
	Material* GetMaterial() const;
	void SetMaterial(Material* m);
	
	virtual float Intersect(const Ray& ray) const = 0;
	virtual vec3 CalcNormal(const vec3& p) const = 0;
};
