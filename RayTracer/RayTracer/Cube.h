#pragma once

#include "Primitive.h"

class Cube : public Primitive
{
private :
	float size;

public:
	Cube();
	Cube(const vec3& p, const float s);
	Cube(const vec3& p, const float s, Material* m);
	Cube(const Cube& c);
	virtual ~Cube();
	Cube& operator=(const Cube& c);
	float GetSize() const { return size; };
	void SetSize(const float s);

	float Intersect(const Ray& ray) const override;

	virtual vec3 CalcNormal(const vec3& p) const override;
};
