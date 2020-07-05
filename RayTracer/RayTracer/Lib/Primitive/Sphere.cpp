#include "Sphere.h"

Sphere::Sphere()
	: Primitive({ 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, { 1.f,1.f,1.f }), radius(0.f)
{
	mat = new Material(Material::Type::MATTE, { 0.f, 1.f, 0.f }, 1.f);
}

Sphere::Sphere(const vec3& p, const float r)
	: Primitive(p, {0.f, 0.f, 0.f}, {1.f,1.f,1.f}), radius(r) 
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

bool Sphere::Intersect(const Ray& ray, vec3 &impact) const
{
	vec3 rayDirection = ray.getDirection();
	vec3 rayOrigin = ray.getOrigin();
	vec3 oc = rayOrigin - position;

	float a = pow(rayDirection.getX(), 2) + pow(rayDirection.getY(), 2) + pow(rayDirection.getZ(), 2);
	float b = 2 * (oc.getX() * rayDirection.getX() +
		oc.getY() * rayDirection.getY() +
		oc.getZ() * rayDirection.getZ()
	);

	float c = pow(oc.getX(), 2) + pow(oc.getY(), 2) + pow(oc.getZ(), 2) - radius * radius;
	float t = pow(b, 2) - (4 * a * c);

	if (t >= 0.f) {
		float t1 = (-b - sqrtf(t)) / (2 * a);
		float t2 = (-b + sqrtf(t)) / (2 * a);

		if ((t1 >= 0 && t1 < t2) || (t1 >= 0 && t2 < 0)) {
			t = t1;
		}
		else {
			t = t2;
		}

		impact.setX(rayOrigin.getX() + (t * rayDirection.getX()));
		impact.setY(rayOrigin.getY() + (t * rayDirection.getY()));
		impact.setZ(rayOrigin.getZ() + (t * rayDirection.getZ()));

		return true;
	}

	return false;
}

vec3 Sphere::CalcNormal(const vec3& p) const
{
	//Primitive::calcNormal(p);
	//Super::calcNormal(p); => UNREAL ENGINE
	//__super::calcNormal(p); => VISUAL STUDIO
	return (p - position).normalize();
}