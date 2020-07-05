#include "Cube.h"

Cube::Cube()
	: position({ 0.f, 0.f, 0.f }), size(0.f)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Cube::Cube(const vec3& p, const float s)
	: position(p), size(s)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Cube::Cube(const vec3& p, const float s, Material* m)
	: Primitive(m), position(p), size(s)
{
	
}

Cube::Cube(const Cube& c)
	: Primitive(c)
{
	position = c.position;
	size = c.size;
	mat = c.mat;
}

Cube::~Cube()
{
}

Cube& Cube::operator=(const Cube& c)
{
	position = c.position;
	size = c.size;
	mat = c.mat;
	return *this;
}

void Cube::SetPosition(const vec3& p)
{
	position = p;
}

void Cube::SetSize(const float s)
{
	size = s;
}

float Cube::Intersect(const Ray& ray) const
{
	return 0.f;
}

vec3 Cube::CalcNormal(const vec3& p) const
{
	return { 0.f, 0.f, 0.f };
}
