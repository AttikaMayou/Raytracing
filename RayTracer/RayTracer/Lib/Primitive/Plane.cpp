#include "Plane.h"

Plane::Plane()
	: axe({1.f, 1.f, 0.f})
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Plane::Plane(const vec3& a)
	: axe(a)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Plane::Plane(const vec3& a, Material* m)
	: Primitive(m), axe(a)
{
}

Plane::Plane(const Plane& p)
	: Primitive(p)
{
	axe = p.axe;
	mat = p.mat;
}

Plane::~Plane()
{
}

Plane& Plane::operator=(const Plane& p)
{
	axe = p.axe;
	mat = p.mat;
	return *this;
}

void Plane::SetAxe(const vec3& a)
{
	axe = a;
}

bool Plane::Intersect(const Ray& ray, vec3& impact) const
{
	float t = 0.f;
	
	return false;
}

vec3 Plane::CalcNormal(const vec3& p) const
{
	return { 0.f, 0.f, 0.f };
}
