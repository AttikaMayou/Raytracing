#include "Cylinder.h"

Cylinder::Cylinder()
	: axe({ 0.f, 1.f, 0.f }), radius(0.f)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Cylinder::Cylinder(const vec3& p, const vec3 a, const float r)
	: axe(a), radius(r)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Cylinder::Cylinder(const vec3& p, const vec3 a, const float r, Material* m)
	: Primitive(m), axe(a), radius(r)
{
	
}

Cylinder::Cylinder(const Cylinder& c)
	: Primitive(c)
{
	position = c.position;
	axe = c.axe;
	radius = c.radius;
	mat = c.mat;
}

Cylinder::~Cylinder()
{
}

Cylinder& Cylinder::operator=(const Cylinder& c)
{
	position = c.position;
	axe = c.axe;
	radius = c.radius;
	mat = c.mat;
	return *this;
}

void Cylinder::SetAxe(const vec3& a)
{
	axe = a;
}

void Cylinder::SetRadius(const float r)
{
	radius = r;
}

bool Cylinder::Intersect(const Ray& ray, vec3& impact) const
{
	return false;
}

vec3 Cylinder::CalcNormal(const vec3& p) const
{
	return { 0.f, 0.f, 0.f };
}
