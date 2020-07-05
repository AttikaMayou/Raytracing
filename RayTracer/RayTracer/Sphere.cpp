#include "Sphere.h"

Sphere::Sphere()
	: radius(0.f)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Sphere::Sphere(const vec3& p, const float r)
	: Primitive(p), radius(r) 
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Sphere::Sphere(const vec3& p, float r, Material* m)
	: Primitive(m), radius(r)
{

}

Sphere::Sphere(const Sphere& s)
	: Primitive(s)
{
	position = s.position;
	radius = s.radius;
	mat = s.mat;
}

Sphere::~Sphere()
{
}

Sphere& Sphere::operator=(const Sphere& s)
{
	radius = s.radius;
	return *this;
}

void Sphere::SetRadius(const float r)
{
	radius = r;
}

float Sphere::Intersect(const Ray& ray) const
{
	vec3 diff = ray.getOrigin() - position;
	float a = diff.dot(diff);
	vec3 v = ray.getDirection();
	v.normalize();
	float b = diff.dot(v);
	float c = diff.dot(diff) - radius * radius;
	float t = b * b - c;
	if (t >= 0.f)
		t = -b - sqrtf(t);
	return t;
}

vec3 Sphere::CalcNormal(const vec3& p) const
{
	//Primitive::calcNormal(p);
	//Super::calcNormal(p); => UNREAL ENGINE
	//__super::calcNormal(p); => VISUAL STUDIO
	return (p - position).normalize();
}