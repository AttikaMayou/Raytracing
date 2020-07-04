#include "Ray.h"

Ray::Ray()
{
	origin = vec3();
	tmin = 0.1f;
	direction = vec3();
	tmax = 0.9f;
}

Ray::Ray(const vec3& o, float min, const vec3& d, float max) : origin(o), tmin(min), direction(d), tmax(max)
{
}

Ray::Ray(const Ray& r) : origin(r.origin), tmin(r.tmin), direction(r.direction), tmax(r.tmax)
{
}

Ray::~Ray()
{
}

Ray& Ray::operator=(const Ray& r)
{
	Ray tmp = r;
	swap(tmp);
	return *this;
}

void Ray::setOrigin(const vec3& o)
{
	origin = o;
}

void Ray::setTMin(float t)
{
	tmin = t;
}

void Ray::setDirection(const vec3& d)
{
	direction = d;
}

void Ray::normalizeDirection()
{
	direction.normalize();
}

void Ray::SetTMax(float t)
{
	tmax = t;
}

void Ray::swap(Ray& r)
{
	std::swap(origin, r.origin);
	std::swap(tmin, r.tmin);
	std::swap(direction, r.direction);
	std::swap(tmax, r.tmax);
}
