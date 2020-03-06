#include "Sphere.h"

Sphere::Sphere() : position({ 0.f, 0.f, 0.f }), radius(0.f)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Sphere::Sphere(const vec3& p, float r) : position(p), radius(r) 
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Sphere::Sphere(const vec3& p, float r, const  Material* m) : position(p), radius(r), Primitive(m)
{

}

Sphere::~Sphere()
{
	delete mat;
}

void Sphere::SetPosition(const vec3& p)
{
	position = p;
}

void Sphere::SetRadius(const float r)
{
	radius = r;
}

void Sphere::SetMaterial(const Material* m)
{
	mat = m;
}

float Sphere::intersect(const Ray& ray) const
{
	vec3 diff = ray.origin - position;
	float a = diff.dot(diff);
	vec3 v = ray.direction;
	v.normalize();
	float b = diff.dot(v);
	float c = diff.dot(diff) - radius * radius;
	float t = b * b - c;
	if (t >= 0.f)
		t = -b - sqrtf(t);
	return t;
}

vec3 Sphere::calcNormal(const vec3& p) const
{
	//Primitive::calcNormal(p);
	//Super::calcNormal(p); => UNREAL ENGINE
	//__super::calcNormal(p); => VISUAL STUDIO
	return (p - position).normalize();
}