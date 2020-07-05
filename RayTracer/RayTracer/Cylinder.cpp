#include "Cylinder.h"

Cylinder::Cylinder()
	: position( {0.f, 0.f, 0.f}), axe({ 0.f, 1.f, 0.f }), radius(0.f)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Cylinder::Cylinder(const vec3& p, const vec3 a, const float r)
	: position(p), axe(a), radius(r)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Cylinder::Cylinder(const vec3& p, const vec3 a, const float r, Material* m)
	: Primitive(m), position(p), axe(a), radius(r)
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

void Cylinder::SetPosition(const vec3& p)
{
	position = p;
}

void Cylinder::SetAxe(const vec3& a)
{
	axe = a;
}

void Cylinder::SetRadius(const float r)
{
	radius = r;
}

float Cylinder::Intersect(const Ray& ray) const
{
	return 0.f;
}

vec3 Cylinder::CalcNormal(const vec3& p) const
{
	return { 0.f, 0.f, 0.f };
}
