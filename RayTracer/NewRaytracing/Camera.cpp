#include "Camera.h";

Camera::Camera() : origin({0.f, 0.f, 0.f}), lowerLeftCorner({ 0.f, 0.f, 0.f }), horizontal({ 0.f, 0.f, 0.f }), vertical({ 0.f, 0.f, 0.f }),
	u({ 0.f, 0.f, 0.f }), v({ 0.f, 0.f, 0.f }), w({ 0.f, 0.f, 0.f }), lensRadius(0.f), time0(0.f), time1(0.f) {}

Camera::Camera(vec3 lookFrom, vec3 lookAt, vec3 vup, float vfov, float aspect, float aperture, float focusDist, float t0, float t1) {
	float theta = vfov * M_PI / 180;
	float h = tan(theta / 2);
	float viewportHeight = 2.0 * h;
	float viewportWidth = aspect * viewportHeight;

	w = unitVector(lookFrom - lookAt);
	u = unitVector(cross(vup, w));
	v = cross(w, u);

	origin = lookFrom;
	horizontal = u * focusDist * viewportWidth;
	vertical = v * focusDist * viewportHeight;
	lowerLeftCorner = origin - horizontal/2 - vertical/2 - w * focusDist;

	lensRadius = aperture / 2;
	time0 = t0;
	time1 = t1;
}

Camera::Camera(const Camera& copy) : origin(copy.origin), lowerLeftCorner(copy.lowerLeftCorner), horizontal(copy.horizontal), vertical(copy.vertical),
u(copy.u), v(copy.v), w(copy.w), lensRadius(copy.lensRadius), time0(copy.time0), time1(copy.time1) {}

Camera::~Camera() {}

Camera& Camera::operator=(const Camera& c)
{
	origin = c.origin;
	lowerLeftCorner = c.lowerLeftCorner;
	horizontal = c.horizontal;
	vertical = c.vertical;
	u = c.u;
	v = c.v;
	w = c.w;
	lensRadius = c.lensRadius;
	time0 = c.time0;
	time1 = c.time1;
	return *this;
}

Ray Camera::getRay(float s, float t) const {
	vec3 rad = Utils::randInUnitDisk() * lensRadius;
	vec3 offset = u * rad.getX() + v * rad.getY();

	return Ray(origin + offset, lowerLeftCorner + horizontal * s + vertical * t - origin - offset);
}
